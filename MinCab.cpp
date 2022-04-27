#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void sorting(int activity[][4], int size)
{
    /*Using bubbleSort Algorithm*/
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {

            /*Comparing the FINISH TIME (HOURS)*/
            if (activity[j][2] > activity[j + 1][2])
            {

                swap(activity[j][0], activity[j + 1][0]);
                swap(activity[j][1], activity[j + 1][1]);
                swap(activity[j][2], activity[j + 1][2]);
                swap(activity[j][3], activity[j + 1][3]);
                // swap(activity[j][4], activity[j+1][4]);
            }
            else if (activity[j][2] == activity[j + 1][2])
            {
                /*If FINISH TIME (HOURS) is equal then comparing FINISH TIME (MINUTES)*/
                if (activity[j][4] > activity[j + 1][4])
                {

                    swap(activity[j][0], activity[j + 1][0]);
                    swap(activity[j][1], activity[j + 1][1]);
                    swap(activity[j][2], activity[j + 1][2]);
                    swap(activity[j][3], activity[j + 1][3]);
                    // swap(activity[j][4], activity[j+1][4]);
                }
                else if (activity[j][3] == activity[j + 1][3])
                {
                    /*If FINISH TIME (HOURS AND MINUTES) is equal then comparing START TIME (HOURS)*/
                    if (activity[j][1] > activity[j + 1][1])
                    {

                        swap(activity[j][0], activity[j + 1][0]);
                        swap(activity[j][1], activity[j + 1][1]);
                        swap(activity[j][2], activity[j + 1][2]);
                        swap(activity[j][3], activity[j + 1][3]);
                        // swap(activity[j][4], activity[j+1][4]);
                    }
                    else if (activity[j][0] == activity[j + 1][0])
                    {
                        /*if FINISH TIME (HOURS AND MINUTES) and START TIME (HOURS) is
                        equal then comparing START TIME MINUTES*/
                        if (activity[j][2] > activity[j + 1][2])
                        {
                            swap(activity[j][0], activity[j + 1][0]);
                            swap(activity[j][1], activity[j + 1][1]);
                            swap(activity[j][2], activity[j + 1][2]);
                            swap(activity[j][3], activity[j + 1][3]);
                            // swap(activity[j][4], activity[j+1][4]);
                        }
                        else if (activity[j][1] == activity[j + 1][1])
                        {
                            /*If FINISH TIME (HOURS AND MINUTES) and START TIME (HOURS AND MINUTES)
                            is equal then comparing ACTIVITY NUMBER*/
                            if (activity[j][0] > activity[j + 1][0])
                            {
                                swap(activity[j][0], activity[j + 1][0]);
                                swap(activity[j][1], activity[j + 1][1]);
                                swap(activity[j][2], activity[j + 1][2]);
                                swap(activity[j][3], activity[j + 1][3]);
                                // swap(activity[j][4], activity[j+1][4]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void display(int activity[][4], int n)
{
    cout << "Activity\tStart Time\tFinish Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "A" << (i + 1) << "\t\t" << activity[i][0] << ":" << activity[i][1] << "\t\t" << activity[i][2] << ":" << activity[i][3] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter Number of Persons: ";
    cin >> n;

    // int activity[n][4];

    // for(int i=0;i<n;i++){

    //     cout<<"\n Enter the Start and End time (hr min hr min) format for Activity "<<i+1<<": ";
    //     cin>>activity[i][0]>>activity[i][1]>>activity[i][2]>>activity[i][3];
    // }

    int activity[6][4] = {
        {1, 0, 2, 0},
        {16, 0, 21, 30},
        {9, 30, 13, 0},
        {21, 30, 22, 30},
        {21, 30, 22, 30},
        {12, 0, 12, 30}};

    cout << "\n The Table for activities\n Before Sorting: " << endl;
    display(activity, n);

    auto start = chrono::high_resolution_clock::now();

    sorting(activity, n);

    cout << endl
         << "After Sorting : \n";
    display(activity, n);

    int cabCounter = 0;

    for (int i = 0; i < n - 1; i++)
    {

        if (activity[i][2] > activity[i + 1][0])
        {
            // cout<<"\n i: "<<i;
            cabCounter++;
        }
        else if (activity[i][2] == activity[i + 1][0])
        {
            if (activity[i][3] >= activity[i + 1][1])
            {
                // cout<<"\n i: "<<i;
                cabCounter++;
            }
        }
    }

    cout << "\n Total Cabs Required: " << cabCounter;

    auto stop = chrono::high_resolution_clock::now();

    double duration = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    duration *= 1e-9;

    cout << "\n Time taken: " << fixed << duration << setprecision(9) << " microseconds" << endl;

    return 0;
}
