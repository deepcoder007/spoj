#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define s(n) scanf("%d",&n)
using namespace std;

int cache[10][10];   // to store the sum of numbers -> first index is the number of digits

void init()
{
  register int i,j,k,l,fixed;
  for(i=0;i<=9;i++)
    cache[1][i]=i*(i+1)/2;   
  for(i=2;i<=9;i++)   // for all the no. of digits
    {
      fixed = 0;    // to store the fixed component associated
      for( j = i-1; j>0 ; j-- )
	fixed+=cache[j][9];
      cache[i][0]=fixed;
      for( j = 1 ; j<=9 ; j++ )   // for each number in this digit
	{
	  cache[i][j]=fixed*j+pow(10,i-1)*j*(j-1)/2+j;
	}
    }
}

int get(int n)  // sum of digits starting from 1 until this number n
{
  int ans = 0 ;  // sum it digit by digit
  register int i=1;
  int fixed=0 ;   // the fixed component of the digits on the left
  while( n )
    {
        cout<<"for n= "<<n<<endl;
      int k = n; 
      int o = k%10;  // the last digit
      k/=10;   // the rest of the number
      ans+=( cache[i][n%10]+k*o*pow(10,i-1) );
      cout<<"Curr inc :"<<(cache[i][n%10]+k*o*pow(10,i-1))<<endl;
      // cout<<" curr ans: "<<ans<<endl;
      n/=10;
      i++;
    }
  cout<<" ret : "<<ans<<endl;
  return ans;
}


int main()
{
  init();
  int i,j;
  while(1)
    {
      s(i);s(j);
      if( i==-1 && j==-1)
	break;
      cout<<get(j)-get(i-1)<<endl;
    }
  return 0;
}
