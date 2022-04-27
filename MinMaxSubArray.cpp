//The time complexity of the Naive method is O(n^2). Using Divide and Conquer approach, we can find the maximum subarray sum in O(nLogn) time
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(int nums[],int n) {
        int sum=0;
        int maximum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maximum=max(maximum,sum);
			if(sum<0)
            {
                sum=0;
            }
        }
        return maximum;
}

int main()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "<< maxSubArray(arr, n);
}
