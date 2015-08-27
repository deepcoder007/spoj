#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

double rem(double b)
{
	double a=11,i=0;
	while(a>=10)
	{
		a=b-10*i;
		i++;
	}
	return a;
	
}

int main()
{
  for(int i=0;i<30;i++)
    cout<<rem(i)<<endl;
  return 0;
}
/*
int main()
{
  int t,n;
  cin>>t;
  while(t--)
    {
      cin>>n;




    }
  return 0;
}
*/
