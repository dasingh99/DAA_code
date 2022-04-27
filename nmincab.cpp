#include <bits/stdc++.h>

using namespace std;

int main()
{
	//pair<int,int> cabtimes;
	
	int noOfCust=0;
	
	cout<<"Enter The Number of Customer"<<endl;
	cin>>noOfCust;
	pair<int,int> cabtimes[noOfCust];
	for(int i=0;i<noOfCust;i++)
	{
		cout<<"Enter Start Timing and Finish Timing of the cab for Customer number  :"<< i+1 <<endl;
		cin>>cabtimes[i].first;
		cin>>cabtimes[i].second;
	}
	sort(cabtimes,cabtimes+noOfCust);
	int cab=1;
	int iterator=0;
	for(int z=1;z<=noOfCust;z++)
	{
		if(cabtimes[z].first>=cabtimes[iterator].second)
		{
			iterator++;
			cout<<"\n Existing car sent for "<<z<<endl;
		}
		else
		{
			cab++;
			cout<<"\n New cab to be used for customer number "<< z <<endl;
		}
	}
	cout<<" \n Minimum number of cars used for  "<<noOfCust<<" customers are: "<<cab<<endl;
}
