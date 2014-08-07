#include<iostream>
#include<cstdio>
using namespace std;


struct coord
{
	int count;  // stores the maximum length of the path uptil now
	int x;     // the vertical coordinate
	int y;     // the horizontal coordinate
}


int main()
{
	int freq[27];
	int arr[51][51];
	int x,y;
	cin>>x>>y;
	int i,j;

	for(i=1;i<27;i++)
		freq[i]=0;
	char c;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			cin>>arr[i][j];
			freq[arr[i][j]-'A'+1]++;  
		}
	}
	int max=0;  // calculate the maximum frequency of the word
	for(i=1;i<=26;i++)
	{
		if( freq[i]>max)
			max=freq[i];
	}
	
	coord arr2[27][max+1];
	for(i=1;i<27;i++)
		for(j=1;j<=max;j++)
			arr2[i][j]={0,0,0};

	// find all letters in arr1
	for(i=1;i<27;

