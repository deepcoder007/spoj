#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define debug(n)   cout<<__LINE__<<" #n "<<n<<endl;
using namespace std;

int a,b;    // the last numbers
string in,str1,str2,str3,str4;
map<string,int> code_map;    // maps the 3 digit code to the digit
map<int,string> rev_code_map;    // reverse maps the digit to the 3 digit string
int tmp1,tmp2,tmp3;

int main()
{
  code_map["063"]=0;
  code_map["010"]=1;
  code_map["093"]=2;
  code_map["079"]=3;
  code_map["106"]=4;
  code_map["103"]=5;
  code_map["119"]=6;
  code_map["011"]=7;
  code_map["127"]=8;
  code_map["107"]=9;

  rev_code_map[0]="063";
  rev_code_map[1]="010";
  rev_code_map[2]="093";
  rev_code_map[3]="079";
  rev_code_map[4]="106";
  rev_code_map[5]="103";
  rev_code_map[6]="119";
  rev_code_map[7]="011";
  rev_code_map[8]="127";
  rev_code_map[9]="107";

  
  while(1)
    {
      cin>>in;
      if( in[0]=='B' ) return 0;   // i.e. the last case
      tmp1=in.find('+');   // the first position of the character +
      str1 = in.substr(0,tmp1);
      str2 = in.substr(tmp1+1);
      str2 = str2.substr(0,str2.size()-1);
      str3=str1; str4=str2;
      a=b=0;
      while(str1.size()) 
	{
	  a=a*10+code_map[str1.substr(0,3)];
	  str1=str1.substr(3);
	}
      while(str2.size())
	{
	  b=b*10+code_map[str2.substr(0,3)];
	  str2=str2.substr(3);
	}
      a+=b;
      str1.clear();
      while(a)
	{
	  str1=rev_code_map[a%10]+str1;
	  a/=10;
	}
      cout<<str3<<'+'<<str4<<'='<<str1<<endl;
    }
  return 0;
}
