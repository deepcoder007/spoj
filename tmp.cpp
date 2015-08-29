
const int N=200005,B=107,P=10000007,size=1000000000;
char s[N];
int n,m,k,H,a[N],f[N],p[N],q[N]; 
bool b[P];
ll g[605][1005],res[1005],ans[1005];

int hash(int i,int j){return (p[i+j]-(1LL*p[i-1]*q[j+1])%P+P)%P;}

void add(ll *a,ll *b)
{
	if (*b>*a) *a=*b; rep(i,*a) a[i]+=b[i]; ++*a;
	rep(i,*a) a[i+1]+=a[i]/size,a[i]%=size; while (!a[*a]) --*a;
}

int main()
{
	scanf("%s",s+1),m=strlen(s+1),a[++n]=27; 
	rep(i,m) a[++n]=s[i]-96,a[++n]=27;
	m=0,q[0]=1; 
	rep(i,n) p[i]=(p[i-1]*B+a[i])%P,q[i]=q[i-1]*B%P;
	rep(i,n)
		if (i<k+f[k] && i+f[k+k-i]<k+f[k]) f[i]=f[k+k-i];
		else{
			for (f[i]=max(k+f[k]-i,0);i-f[i] && i+f[i]<=n && a[i-f[i]]==a[i+f[i]];++f[i])
				if (a[i+f[i]]<27) if (!b[H=hash(i,f[i])]) b[H]=1,++m;
//					printf("%d i=%d %d %d\n",a[i+f[i]],i,f[i],hash(i,f[i]));
			if (i+f[i]>k+f[k]) k=i;
		}
//	rep(i,n) printf("%d ",f[i]); puts(""); printf("%d\n",m);
	scanf("%d",&n);
	*ans=*g[0]=g[0][1]=1; rep(i,n) mul(g[i-1],m,g[i]);
	if (n&1) mul(g[n/2+1],n,res),add(ans,res);
	else mul(g[n/2],n/2,res),add(ans,res),mul(g[n/2+1],n/2,res),add(ans,res);
	rep(i,n) add(ans,g[__gcd(n,i)]); div(ans,2*n),prt(ans);
//	printf("%d\n",*ans); for (;;);
	return 0;
}
