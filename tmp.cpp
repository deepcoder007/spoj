typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef long long int lld;

const int N = 10100;

class segTree
{
	public:
		struct tree
		{
			int val;
		};
		int n;
		vector< tree > st;
		segTree(int _n)
		{
			n = _n;
			st.resize(6*n + 10);
		}
		segTree() {}
		~segTree()
		{
			st.clear();
			n = 0;
		}

		tree merge(tree A,tree B)
		{
			tree C;
			C.val = max(A.val,B.val);
			return C;
		}

		void update(int s,int e,int node,int pos,int v)
		{
			if(s>e) return;
			if(s==e) 
			{
				st[node].val = v;
				return;
			}

			int l = node<<1;
			int r = l|1;
			int m = (s+e)>>1;

			if(pos>m)
				update(m+1,e,r,pos,v);
			else
				update(s,m,l,pos,v);

			st[node] = merge(st[l],st[r]);

		}

		void update(int pos,int v)
		{
			update(0,n-1,1,pos,v);
		}

		tree query(int s,int e,int a,int b,int node)
		{
			if((s>=a && e<=b)) return st[node];
			tree L,R,A;
			int l = node<<1;
			int r = l|1;
			int m = (s+e)>>1;
			if(a>m) return query(m+1,e,a,b,r);
			if(b<=m) return query(s,m,a,b,l);

			R = query(m+1,e,a,b,r);
			L = query(s,m,a,b,l);
			return merge(R,L);
		}

		int query(int l, int r)
		{
			if(l>r) return 0;
			return query(0,n-1,l,r,1).val;
		}
};

int chainNo[N], chainHead[N], height[N], par[N];
int baseArr[N], posInBase[N];
int pos = 0;
int p[20][N];
int idx = 0;
int sub[N];
int LN = 14;
vector< pii > edge;
segTree st(N);
vi adj[N],cost[N];

int lca(int u,int v)
{
	if(height[u]>height[v]) swap(u,v);
	int diff = height[v] - height[u];
	for(int j=0;j<LN;j++) if((diff>>j)&1) v = p[j][v];
	if(u==v) return u;
	for(int j=LN-1;j>=0;j--)
		if(p[j][u]!=p[j][v])
		{
			u = p[j][u];
			v = p[j][v];
		}
	return p[0][v];
}


void hld(int node,int cst,int p = -1)
{
	if(chainHead[idx]==-1)
		chainHead[idx] = node;

	chainNo[node] = idx;
	posInBase[node] = pos;
	baseArr[pos++] = cst;
	
	int ch = -1,mm = 0,cc = 0;
	for(int i=0;i<adj[node].sz;i++)
	{
		int u = adj[node][i];
		if(u!=p)
			if(sub[u]>mm)
			{
				ch = u;
				cc = cost[node][i];
				mm = sub[u];
			}
	}
	if(ch!=-1)
		hld(ch,cc,node);
	for(int i=0;i<adj[node].sz;i++)
	{
		int u = adj[node][i];
		if(u!=p && u!=ch)
		{
			idx++;
			hld(u,cost[node][i],node);
		}
	}
}

int main()
{
	
		hld(0,0);
		for(int i=0;i<pos;i++)
			st.update(i,baseArr[i]);
		for(int i=0;i<n;i++)
			p[0][i] = par[i];

		for(int j=1;j<LN;j++)
			for(int i=0;i<n;i++)
				if(p[j-1][i]!=-1)
					p[j][i] = p[j-1][p[j-1][i]];

		char s[100];
		int a,b;
		while(scanf("%s",s))
		{
			if(s[0]=='D') break;
			scanf("%d%d",&a,&b);
			if(s[0]=='C')
			{
				a--;
				int u = edge[a].F;
				int v = edge[a].S;
				if(par[u] == v) swap(u,v);
				st.update(posInBase[v],b);
			}
			else if(s[0]=='Q')
			{
				a--;b--;
				int u = a;
				int v = b;
				int l = lca(u,v);
				int ans = INT_MIN;
				while(chainNo[l]!=chainNo[u])
				{
					ans = max(ans,st.query(posInBase[chainHead[chainNo[u]]],posInBase[u]));
					u = chainHead[chainNo[u]];
					u = par[u];
				}
				ans = max(ans,st.query(posInBase[l]+1,posInBase[u]));
				u = v;
				while(chainNo[l]!=chainNo[u])
				{
					ans = max(ans,st.query(posInBase[chainHead[chainNo[u]]],posInBase[u]));
					u = chainHead[chainNo[u]];
					u = par[u];
				}
				ans = max(ans,st.query(posInBase[l]+1,posInBase[u]));
				printf("%d\n",ans);
			}
		}
	

