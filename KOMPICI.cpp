#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
int arr[500005];  // the bitset of the numbers
int freq[2000];   // the freq of the different words

inline int max(int i,int j)
{
  if( i>j ) return i;
  else return j;
}

// returns the binary representaiton of the string
/*
string get_binary(int n)
{
  string str1;  
  while( n )
    {
      if( n&1 )   // if the last digit is 1
	str1.push_back('1');
      else 
	str1.push_back('0');
      n>>=1;
    }
  string str2;
  register int i;
  for(i=str1.size()-1; i>=0 ; i-- )
    str2.push_back(str1[i]);
  return str2;
}
*/

int main()
{
  register int n;
  cin>>n;
  string str;
  register int i,j;
  register int l;
  memset(arr,0,sizeof(arr));
  memset(freq,0,sizeof(freq));
  int mx = 0;    // the max freq;
  for(i=0;i<n;i++)
    {
      cin>>str;
      l=str.size();
      for(j=0;j<l;j++)
	{
	  arr[i]|=(1<<(str[j]-'0'));
	}
      //      cout<<"binary : "<<get_binary(arr[i])<<endl;
      freq[arr[i]]++;
      mx=max(mx,arr[i]);     // the maximum value of the freq.
    }
  register long long count=0;
  /*
  cout<<"print freq"<<endl;
  for(i=1;i<=mx;i++)
    cout<<get_binary(i)<<"\t"<<freq[i]<<endl;
  */
  for(i=1;i<=mx;i++) 
    {
      count+=((freq[i]-1)*(freq[i])/2);
      for(j=i+1;j<=mx;j++)
	{
	  if( (i&j)>=1 )
	  count+= (freq[i]*freq[j]);
	}
    }
  cout<<count<<endl;
  return 0;

}
