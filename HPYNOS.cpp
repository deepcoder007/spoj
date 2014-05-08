#include<iostream>
#include<set>
using namespace std;


int sum(int n)
{
	register int N=n;
	register int deg;
	int sum=0;
	while(N)
	{
		deg=N%10;
		sum+=deg*deg;
		N/=10;
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	set<int> s;
	int count=0;
	while( n!=1 && s.find(n)==s.end() )
	{
		s.insert(n);
		n=sum(n);
		count++;
	}
	if( count && s.find(n)==s.end() )
	cout<<count<<endl;
	else 
		cout<<-1<<endl;
	return 0;
}


