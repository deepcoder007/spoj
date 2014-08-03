#include<iostream>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;


// Sort v according to the character index i , from pos x to y inclusive
void linear_sort(vector<string>& v,int i,int x,int y)
{
	int b[10];
	int j;
	for(j=0;j<10;j++) b[j]=0;
	for(j=x;j<=y;j++)
		b[v[j][i]-'0']++;
	for(j=1;j<10;j++)
		b[j]+=b[j-1];
	vector<string>& next;





}




void test()
{
	int n;
	cin>>n;
	int i;
	vector<string> v;
	string tmp_str;
	for(i=0;i<n;i++)
	{
		cin>>tmp_str;
		v.push_back(tmp_str);
	}
	linear_sort(v,0,0,v.size()-1);




}

int main()
{
	int n;
	cin>>n;
	while(n--)
		test();
	return 0;
}

