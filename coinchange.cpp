//For sorting n coins O(nlogn).
//While loop, the worst case is O(total)
//Complexity for coin change problem becomes O(n log n) + O(total).
#include <iostream>

using namespace std;

int minCoin(int arr[], int m, int A)
{
   int maxnum=100;
   if(A == 0)
     return 0;
   int min = maxnum;
   for(int i = 0;i<m;i++)
   {
      if(arr[i] <= A)
      {
         int minnum = minCoin(arr, m, A-arr[i]);
         if(minnum + 1 < min && minnum != maxnum)
           min = minnum + 1;
      }
   }
 return min;
}

int main(){

    int coins,A,arr[100],minicoin;
    cout<<"Enter the number of coins: ";
    cin>>coins;
    cout<<"Enter the target value to be achieved: ";
    cin>>A;
    for(int i=0;i<coins;i++){
        cout<<"Coin no "<<i+1<<": ";
        cin>>arr[i];
    }
    minicoin = minCoin(arr,coins,A);
    cout<<"Minimum Number of coins required to reach the target is: "<<minicoin;
}
