#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

char str[1000009];
char out[1000009];
bool odd;
int l;
int t;
int i,j,k;

bool charcmp(char* a,char* b)  // if true then both the strings are same
{
	int l1=strlen(a);
	int l2=strlen(b);
	if(l1!=l2) return false;
	int s;
	for(s=0;s<l1;s++)
	{
		if( a[s]!=b[s] ) return false;
	}
	return true;
}

char* copy_str(char* a)
{
	int l1=strlen(a);
	char *tmp=new char[l1+1];
	int s;
	for(s=0;s<l1;s++)
		tmp[s]=a[s];
	return tmp;
}

char* reverse_str(char* a)
{
	int l1=strlen(a);
	char* tmp=new char[l1+1];
	int s;
	for(l1--,s=0;l1>=0;l1--,s++)
		tmp[s]=a[l1];
	return tmp;
}

char* succ_str(char* a)     // return the successor of the folowing string
{
	int l1=strlen(a);
	// first check if all the element are '9'
	bool flag=false;      // if this is true then it means all are not 9
	int s;
	for(s=0;s<l1;s++)
	{
		if( a[s]!='9' )
		{
			flag=true;
			break;
		}
	}
	if( !flag ) // i.e. if all are 9's 
	{
		char* tmp=new char[l1+2];
		for(s=0;s<=l1;s++)
			tmp[s]='0';
		tmp[0]='1';
		return tmp;
	}
	else
	{
		char* tmp=new char[l1+1];
		for(s=l1-1;s>=0 && s=='9'; s-- );    // will stop at the first non 9 char from right
		int z;
		for(z=0;z<s;z++)
			tmp[z]=a[z];
		tmp[s]=a[s]+1;
		for(z=s+1 ; z<l1 ;z++ )
			tmp[z]='0';
		return tmp;
	}
}


int main()
{
	cin>>str;
	cout<<succ_str(str)<<endl;
	return 0;
}

	




/*


void test()
{
	scanf("%s",str);
	int l=strlen(str);
	if( l%2 == 1 ) odd=true;
	else odd=false;
	int center;
	if( odd ) center = l/2;
	else center = l/2 -1 ;    // in case of even number of elements , center will be the last element copied
	for( i=0 ; i<=center ; i++ )
	{
		out[i]=str[i];
	}

}


int main()
{
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
*/
