#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=200005;
const int mod=1e9+7;

int fa[N], dep[N], siz[N], top[N], son[N], tid[N], tim, n, u, v, w, a[N], b[N], q;
vi g[N];
ll ans;

template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n;T a1[N],a2[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,0);fill_n(a1+1,n=_n,0);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p]+=d; }
	void add(int l,int r,T d) {
		add(a1, l, d), add(a1, r + 1, -d);
		add(a2, l, d * (l - 1)), add(a2, r + 1, -d * r);
	} 
	T sum(T *a,int p) { T r=0; for(; p>=1; p-=p & -p) r+=a[p]; return r; }
	T pre(int p) { return !p ? 0 : sum(a1, p) * p - sum(a2, p);}
	T qry(int l,int r) {return pre(r)-pre(l-1); }
};

Fenwick<int> fen;

void init()
{
	memset(son,-1,sizeof(son));
	tim=0;
}
void dfs1(int u,int pre,int d)
{
    dep[u]=d;
    fa[u]=pre;
    siz[u]=1;
    rep(i, 0, sz(g[u]))
    {
        int v=g[u][i];
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;
    tid[u]=++tim;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    rep(i, 0, sz(g[u]))
    {
        int v=g[u][i];
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

bool cmp(int a, int b) {return a > b;}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(v);
		g[v].pb(u);
		a[i] = w;
	}
	sort(a + 1, a + n);
	fen.ini(n);
	init();
	dfs1(1,0,1);
	dfs2(1,1);
	cin >> q;
	//rep(i, 1, n+1) dd(top[i]); 
	rep(cas, 1, q+1) {
		cin >> u >> v;
		//dd(top[u]);de(top[v]);
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u,v);
			//dd(tid[top[u]]);de(tid[u]);
			fen.add(tid[top[u]],tid[u],1);
			u = fa[top[u]];
		}
		if (dep[u] < dep[v]) swap(u,v);
		if (tid[u] >= tid[v] + 1) fen.add(tid[v] + 1,tid[u],1);
	} 
	//de(fen.qry(4,4));
	rep(i, 2, n+1) b[i - 1] = fen.qry(i,i);
	//rep(i, 1, n) dd(b[i]);
	sort(b + 1, b + n, cmp);
	rep(i, 1, n) ans += 1ll * b[i] * a[i];
	cout << ans;
	return 0;
}

