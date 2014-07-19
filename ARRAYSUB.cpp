#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

int arr[1000010];
int out[1000010];

int main()
{
    int n;
    cin>>n;
    int k;
    set<int> k_set;
    int i,j;
    for(i=0;i<n;i++)
	    cin>>arr[i];
    cin>>k;  
    for(i=0;i<(k-1);i++)
	    k_set.insert(-arr[i]);
    for(i=k-1;i<n;i++)
    {
	    k_set.insert(-arr[i]);
	    out[i-k+1]=(-1)*(*k_set.begin());
	    k_set.erase(-arr[i-k+1]);
    }
    for(i=0;i<=(n-k);i++)
	    printf("%d ",out[i]);
    cout<<endl;
    return 0;
}


