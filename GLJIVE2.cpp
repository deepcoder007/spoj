#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int main()
{
	bool flag=false;
	int sum=0;
	int arr[10];
	cin>>arr[0];
	cin>>arr[1];
	cin>>arr[2];
	cin>>arr[3];
	cin>>arr[4];
	cin>>arr[5];
	cin>>arr[6];
	cin>>arr[7];
	cin>>arr[8];
	cin>>arr[9];
	sum+=arr[0];  // 1st one is added by default
	if( abs((float)(sum-100))>=abs((float)(sum+arr[1]-100))) sum+=arr[1]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[2]-100))) sum+=arr[2]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[3]-100))) sum+=arr[3]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[4]-100))) sum+=arr[4]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[5]-100))) sum+=arr[5]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[6]-100))) sum+=arr[6]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[7]-100))) sum+=arr[7]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[8]-100))) sum+=arr[8]; else flag=true;
	if( flag==false && abs((float)(sum-100))>=abs((float)(sum+arr[9]-100))) sum+=arr[9]; else flag=true;
	cout<<sum<<endl;
	return 0;
}
