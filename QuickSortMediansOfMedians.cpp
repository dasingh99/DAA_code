#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int get_median(int input[], int n)
{
    sort(input, input + n);
    return input[n / 2];
}

int split(int input[], int first, int last, int pivot)
{
    auto i = first - 1;
    for (auto j = first; j <= last; j++)
    {
        if (input[j] <= pivot)
        {
            i++;
            std::swap(input[i], input[j]);
        }
    }
    for (auto j = first; j <= last; j++)
    {
        if (input[j] == pivot)
        {
            std::swap(input[i], input[j]);
            break;
        }
    }
    return i;
}

int kth_smallest(int input[], int first, int last, int k)
{
    int n = last - first + 1;
    if (n <= 5)
    {
        sort(input + first, input + last + 1);
        return first + k - 1;
    }
    int length = (n + 4) / 5;
    int medians[length];

    for (auto i = 0; i < length; i++)
    {
        auto first_index = first + i * 5;
        auto last_index = min(first + (i + 1) * 5 - 1, last);
        medians[i] = get_median(input + first_index, last_index - first_index + 1);
    }
    int final_median = (length == 1) ? medians[0] : medians[kth_smallest(medians, 0, length - 1, (length) / 2)];

    int pivot = split(input, first, last, final_median);
    if (pivot - first == k - 1)
        return pivot;
    else if (pivot - first < k - 1)
        return kth_smallest(input, pivot + 1, last, k - (pivot - first + 1));
    return kth_smallest(input, first, pivot - 1, k);
}

void print_array(int[], int);
int split(int[], int, int, int);

void quicksort(int input[], int first, int last)
{
    if (last <= first)
        return;
    int pos = kth_smallest(input, first, last, (last - first + 1) / 2);
    quicksort(input, first, pos - 1);
    quicksort(input, pos + 1, last);
}

void display_array(int input[], int n)
{
    for (auto i = 0; i < n; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
        input[i] = 10000 + (rand() % 1000);
    cout << "The Generated array is: ";
    display_array(input, n);

    auto start = chrono::high_resolution_clock::now();
    quicksort(input, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    double duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
    duration *= 1e-9;
    cout << "\nThe Sorted array is: ";
    display_array(input, n);
    cout << "\n Time taken: " << fixed << duration << setprecision(9) << " microseconds" << endl;

    return 0;
}
