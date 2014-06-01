#include<stdio.h>
#define LL long long
int main()
{
 int t;
 scanf("%d",&t);
 while(t--){
  LL a,b,c,i,j;
  scanf("%lld%lld%lld",&a,&b,&c);
  LL n=(c*2)/(a+b);
  LL d=(b-a)/(n-5);
  LL m=a-2*d;
  printf("%lld\n",n);
  for(i=m,j=0;j<n;i+=d,j++){
   printf("%lld ",i);
  }
  printf("\n");
 }
 return 0;
}
