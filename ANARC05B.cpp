#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int arr1[10010];
int arr2[10010];
int n1,n2;

// A simple problem of dynamic programming
// All arrays are 1-ary
inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

int main()
{
	vector<int> intersect;
	int i,j,k;
	int s1,s2,sum;
	int x,y,z;
	while(1)
	{
		cin>>n1;
		if(n1==0) break;
		for(i=1;i<=n1;i++)
		{ cin>>arr1[i];  }
		cin>>n2;
		for(i=1;i<=n2;i++)
		{ cin>>arr2[i]; }
		i=j=1;  // the pointers of arr1 and arr2 respectively
		intersect.clear();
		while(i<=n1 || j<=n2)
		{
			if(arr1[i]==arr2[j] && i<=n1 && j<=n2)
			{
				intersect.push_back(arr1[i]);
				//cout<<"Intersection :"<<arr1[i]<<endl;
				i++;j++;
			}
			else if(arr1[i]<arr2[j])
				i++;
			else j++;
		}
		//cout<<"ij :"<<i<<j<<endl;
		i=j=1;
		s1=s2=sum=0;
		//cout<<"k : "<<intersect.size()<<endl;
		for(k=0;k<intersect.size();k++)
		{
			s1=0;
			for(;arr1[i]<=intersect[k] && i<=n1;i++)
			{ s1+=arr1[i];  }
			s2=0;
			for(;arr2[j]<=intersect[k] && j<=n2;j++)
			{ s2+=arr2[j];  }
			sum+=max(s1,s2);
			//cout<<"Sum added :"<<max(s1,s2)<<endl;
			//cout<<"s1:"<<s1<<endl;
			//cout<<"s2:"<<s2<<endl;
		}
		s1=s2=0;
		for(;i<=n1;i++)
			s1+=arr1[i];
		for(;j<=n2;j++)
			s2+=arr2[j];
		sum+=max(s1,s2);
		//cout<<"Sum added :"<<max(s1,s2)<<endl;
		cout<<sum<<endl;
	}
	return 0;
}


