#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
int arr[500005];  // the bitset of the numbers



int main()
{
  register int n;
  cin>>n;
  string str;
  register int i,j;
  register int l;
  memset(arr,0,sizeof(arr));
  for(i=0;i<n;i++)
    {
      cin>>str;
      l=str.size();
      for(j=0;j<l;j++)
	{
	  arr[i]|=(1<<(str[j]-'0'));
	}
    }
  register long long count=0;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if( (arr[i] & arr[j]) )
	count++;
  cout<<count<<endl;
  return 0;

}
