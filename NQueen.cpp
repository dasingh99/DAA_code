//The time complexity is O(n^2) because we are selecting if we can put or not put a Queen at that place
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <stdbool.h>
#include <stdio.h>

using namespace std;
int grid[10][10];
int a = 0;

void print(int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
bool isSafe(int col, int row, int n)
{

    // Check this row on left side
    for (int i = 0; i < row; i++)
    {
        if (grid[i][col])
        {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j])
        {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i >= 0 && j < n; j++, i--)
    {
        if (grid[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solve(int n, int row)
{

    // If all queens are placed then return true
    if (n == row)
    {
        a++;
        cout << a << endl;
        print(n);
        return true;
    }

    bool res = false;
    for (int i = 0; i <= n - 1; i++)
    {
        // Check if the queen can be placed on board[i][col]

        if (isSafe(i, row, n))
        {

            // Place this queen in board[i][col]
            grid[row][i] = 1;

            res = solve(n, row + 1) || res;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            grid[row][i] = 0;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }

    if (n < 4)
    {
        cout << "Invalid value" << endl;
        return 0;
    }
    auto start = chrono::high_resolution_clock::now();
    bool res = solve(n, 0);
    if (res == false)
    {
        cout << -1 << endl; // if there is no possible solution
    }
    else
    {
        cout << endl;
    }
    cout << "\n Total no of solutions are: " << a << endl;

    auto stop = chrono::high_resolution_clock::now();

    double duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    duration *= 1e-9;

    cout << "\n Time taken: " << fixed << duration << setprecision(9) << " microseconds" << endl;

    return 0;
}
