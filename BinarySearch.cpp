/*
Time Complexities

Best case complexity: O(1)
Average case complexity: O(log n)
Worst case complexity: O(log n)
Space Complexity

The space complexity of the binary search is O(1).
*/
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void linearSearch(int a[], int n, int key)
{
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        if (key == a[j])
        {
            cout << "\nElement is found at index " << j + 1 << " \n";
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\nElement is not found in array";
    }
}

int binarySearch(int array[], int x, int low, int high)
{
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, choice, bs;
    // srand(time(0);
    n = 300 + (rand() % 101);

    int a[n];

    cout << "\nSize of the Array is " << n << " elements" << endl;
    cout << "Entering the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    cout << "\nDisplaying elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    for (int k = 0; k < 15; k++)
    {
        int key, count = 0;

        cout << "\n\nTest case number:" << k + 1 << " " << endl;

        cout << "\nEnter the element you want to search:";
        cin >> key;

        cout << "\nPerforming Linear Search for the key";
        auto start = chrono::high_resolution_clock::now();
        linearSearch(a, n, key);
        auto stop = chrono::high_resolution_clock::now();
        double duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
        duration *= 1e-9;
        cout << "\n Time taken: " << fixed << duration << setprecision(9) << " microseconds" << endl;

        cout << "\nPerfoming Binary Search for the key:";

        sort(a, a + n);

        cout << "\nSorted Array:" << endl;

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        start = chrono::high_resolution_clock::now();
        bs = binarySearch(a, key, 0, n - 1);
        if (bs == -1)
            cout << "\nElement not found" << endl;
        else
            cout << "\nElement is found at index " << bs + 1 << endl;

        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
        duration *= 1e-9;
        cout << "\n Time taken: " << fixed << duration << setprecision(9) << " microseconds" << endl;
    }

    return 0;
}
