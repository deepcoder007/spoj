#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

string str1,str2;
string b1,b2;
int l1,l2;

inline void test()
{
  cin>>str1>>str2;
  b1=str1; b2=str2;
  int l1=str1.size(); l2=str2.size();
  register int i,j;
  j=l1*l2;
  for( i=0;i<=j;i++ )    // these many iterations only
    {
      if( str1.size()==str2.size() && str1.find(str2)!=string::npos )
	{
	  cout<<"YES"<<endl;
	  return ;
	}
      else if( str1.find(str2)!=string::npos )    // i.e. str2 is a substring of str1
	{
	   str1=str1.substr(str2.size());
	   str2=b2;    // replenish the used string
       	}
      else if( str2.find(str1)!=string::npos )
	{
	  str2=str2.substr(str1.size());
	  str1=b1;   // replenish the used string
	}
      else
	{
	  cout<<"NO"<<endl;
	  return ;
	}
    }
  cout<<"NO"<<endl;
  return ;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
    test();
  return 0;
}
