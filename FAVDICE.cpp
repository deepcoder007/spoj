#include<cstdio>
int main()
{
    int t,num,i;
    scanf("%d",&t);
    double ans;
    while(t--)
    {
        ans=0.0;
        scanf("%d",&num);
        double k=num;
        for(i=num;i>=1;i--)
        {
            ans+=num/k;
            k=k-1;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
    
}
