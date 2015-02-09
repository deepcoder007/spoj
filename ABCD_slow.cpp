#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<cstring>
using namespace std;



inline int min(int a,int b)
{
	if( a< b ) return a;
	else return b;
}

inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

enum mask{ N, A,B,C,D };   
mask code[50005];
string str;
string out;
int n;   // stores the number of each character
int a_c,b_c,c_c,d_c;  // will store the count of each number

bool process(int i)   // process the i'th position in the seq. -> true means all the current value of mask is valid
{
	if( i == 0 )   // if the first position -> no worry about exceeding n
	{
		if( str[i]=='A' )   
		{
			b_c++;
			out[i]='B';
			if( process(i+1) ) return true;
			b_c--;
			c_c++;
			out[i]='C';
			if( process(i+1) ) return true;
			c_c--;
			d_c++;
			out[i]='D';
			if( process(i+1) ) return true;
			d_c--;
		}
		else if( str[i]=='B' )   
		{
			a_c++;
			out[i]='A';
			if( process(i+1) ) return true;
			a_c--;
			c_c++;
			out[i]='C';
			if( process(i+1) ) return true;
			c_c--;
			d_c++;
			out[i]='D';
			if( process(i+1) ) return true;
			d_c--;
		}
		else if( str[i]=='C' )   
		{
			a_c++;
			out[i]='A';
			if( process(i+1) ) return true;
			a_c--;
			b_c++;
			out[i]='B';
			if( process(i+1) ) return true;
			b_c--;
			d_c++;
			out[i]='D';
			if( process(i+1) ) return true;
			d_c--;
		}
		else if( str[i]=='D' )   
		{
			a_c++;
			out[i]='A';
			if( process(i+1) ) return true;
			a_c--;
			b_c++;
			out[i]='B';
			if( process(i+1) ) return true;
			b_c--;
			c_c++;
			out[i]='C';
			if( process(i+1) ) return true;
			c_c--;
		}
	}
	else if( i== (str.size()-1) )
	{
		if( a_c < n && str[i]!='A' && out[i-1]!='A' )   // it should be a
		{
			a_c++;
			out[i]='A';
			return true;
		}
		else if( b_c < n && str[i]!='B' && out[i-1]!='B' )
		{
			b_c++;
			out[i]='B';
			return true;
		}
		else if( c_c < n && str[i]!='C' && out[i-1]!='C' )
		{
			c_c++;
			out[i]='C';
			return true;
		}
		else if( d_c< n && str[i]!='D' && out[i-1]!='D' )
		{
			d_c++;
			out[i]='D';
			return true;
		}
		else
			return false;  // no.solution exist
	}
	else 
	{
		if( a_c < n && str[i]!='A' && out[i-1]!='A' )   // it should be a
		{
			a_c++;
			out[i]='A';
			if( process(i+1) ) return true;
			a_c--;
		}
		if( b_c < n && str[i]!='B' && out[i-1]!='B' )
		{
			b_c++;
			out[i]='B';
			if( process(i+1) ) return true;
			b_c--;
		}
		if( c_c < n && str[i]!='C' && out[i-1]!='C' )
		{
			c_c++;
			out[i]='C';
			if( process(i+1) ) return true;
			c_c--;
		}
		if( d_c< n && str[i]!='D' && out[i-1]!='D' )
		{
			d_c++;
			out[i]='D';
			if( process(i+1) ) return true;
			d_c--;
		}
		return false;  // no.solution exist
	}
}


int main()
{
	cin>>n;
	out.clear();   // the output string
	cin>>str;   // stores the input seq.
	out = string(n*2,'0');
	register int i,j;
	a_c=0,b_c=0,c_c=0,d_c=0;  // the count of various numbers
	for(i=0;i<str.size() ;i++)
	{
		if( str[i]=='A')
			a_c++;
		else if( str[i] == 'B')
			b_c++;
		else if( str[i] == 'C' )
			c_c++;
		else
			d_c++;
	}
	memset(code, 0, sizeof(code) ) ;   // set all to none
	if( process(0) )
		cout<<out<<endl;
	else
		cout<<"No seq found"<<endl;


	return 0;

}




