#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

int t,n;
char str[1010];
int freq1[26];   // frequency of starting
int freq2[26];   // frequency of ending
bool err;        // the error flag
bool start;      //found the start
bool end;        //found the end

void test()
{
	register int i,j;
	err=false; start=false;  end=false;
	scanf("%d",&n);
	for(i=0;i<26;i++)
	{	freq1[i]=freq2[i]=0;  }
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		j=strlen(str);
		freq1[str[0]-'a']++;
		freq2[str[j-1]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(freq1[i]==freq2[i]) continue;
		else if(freq1[i]==(freq2[i]+1))
		{
			if(start) err=true;
			else start=true;
		}
		else if(freq2[i]==(freq1[i]+1))
		{
			if(end) err=true;
			else end=true;
		}
		else err=true;
	}
	if( err==false )
	{ printf("Ordering is possible.\n"); }
	else
	{ printf("The door cannot be opened.\n"); }
}


int main()
{
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
