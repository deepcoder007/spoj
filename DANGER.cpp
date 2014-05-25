#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;

int josephus(int n)
{
	return (2*(n-pow(2.0,(double)(int)(log(n)/log(2))))+1);
}


int main()
{
	string str;
	int a;
	do{
		cin>>str;
		if(str=="00e0") break;
		a=(str[0]-'0')*10+(str[1]-'0');
		a=a*pow(10.0,(double)(str[3]-'0'));
		cout<<josephus(a)<<endl;
	}while(1);
	return 0;
}

