#include <iostream>
using namespace std;

// function to return maximum element using recursion
int findMaxRec(int A[], int n)
{
    if (n == 1)
        return A[0];
    return max(A[n - 1], findMaxRec(A, n - 1));
}

// function to print Minimum element using recursion
int findMinRec(int A[], int n)
{
    if (n == 1)
        return A[0];
    return min(A[n - 1], findMinRec(A, n - 1));
}

int main()
{
    int A[10];
    int n;
    cout << "Enter how many Numbers you want to enter: ";
    cin >> n;

    cout << "Enter the Numbers : ";

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "\nMax of the Number: " << findMaxRec(A, n) << endl;
    cout << "Min of the Numbers: " << findMinRec(A, n) << endl;
    return 0;
    
}