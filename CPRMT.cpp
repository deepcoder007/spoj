#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
	string s1,s2;
	char ss1[1010],ss2[1010];
	int i1,i2;
	int i;
	vector<char> out;
	string s3;
	bool change;  // to record if any change was made
	while( scanf("%s",ss1)!=EOF)
	{
		scanf("%s",ss2);
		s1=ss1;
		s2=ss2;
		out.clear();
		s3.clear();
		for( i=0;i<26;i++)   //i.e. for all characters
		{
			do
			{
				i1=s1.find('a'+i);
				i2=s2.find('a'+i);
				change=false;
				if( i1!=string::npos && i2!=string::npos )
				{
					change=true;
					s1.erase(i1,1);
					s2.erase(i2,1);
					out.push_back('a'+i);
				}
			}while(change);
		}
		sort(out.begin(), out.end() );
		for(i=0;i<out.size();i++)
		{ s3.push_back(out[i]); }
		cout<<s3<<endl;
	}
	return 0;
}

