#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int son[N],dep[N],fa[N],tid[N],top[N],tim,siz[N],n,m,q,u,v,l,r,a[N],op,root,lca,num;
vector<int> g[N];
ll x,ans;

template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n; T a1[N],a2[N];
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

Fenwick<ll> fen1,fen2;

void dfs1(int u,int pre,int d) {
	dep[u]=d;fa[u]=pre;siz[u]=1;
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if (v!=pre) {
			dfs1(v,u,d+1);
			siz[u]+=siz[v];
			if (son[u]==-1||siz[v]>siz[son[u]]) son[u]=v;
		}
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	tid[u]=++tim;
	if (son[u]==-1) return;
	dfs2(son[u],tp);
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if (v!=son[u]&&v!=fa[u]) dfs2(v,v);
	}
} 

void init(){
	memset(son,-1,sizeof(son));
	tim=0;
	dfs1(1,0,1);
	dfs2(1,1);
	fen1.ini(N);
	fen2.ini(N);
}

int getlca(int u,int v){
	while (top[u]!=top[v]) {
		if (dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}

int getson(int u,int v){
	while (top[u]!=top[v] && dep[fa[top[u]]]>dep[v]) u=fa[top[u]];
	if (top[u]!=top[v]) return top[u];
	return son[v];
}

void upd2(int u,ll x) {
	while (u) {
		l=tid[top[u]];r=tid[u];
		fen1.add(l,r,x);
		u=fa[top[u]];
	}
}

void upd(int u,ll x) {
	fen2.add(tid[u],tid[u],x);
	upd2(fa[u],x*siz[u]);
}

ll ask(int u){
	ll res=0;int v=u;
	while (u) {
		l=tid[top[u]];r=tid[u];
		res+=fen2.qry(l,r);
		u=fa[top[u]];
	}
	return fen1.qry(tid[v],tid[v])+res*siz[v];
}

int MIN(int u,int v){
	return dep[u]>dep[v]?u:v;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,n) {
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	init();
	rep(i,1,n+1) upd2(i,a[i]);
	rep(i,1,q+1) {
		cin>>op;
		if (op==1) cin>>root;
		else if (op==2) {
			cin>>u>>v>>x;num=0;
			lca=getlca(u,v);
			lca=MIN(getlca(u,root),lca);
			lca=MIN(getlca(v,root),lca);
			if (lca==root) upd(1,x);
			else {
				int tmp=getlca(root,lca);
				if (tmp==root || tmp!=lca) upd(lca,x);
				else {
					int w=getson(root,lca);
					upd(1,x);upd(w,-x);
				}
			}
		}
		else if (op==3) {
			cin>>lca;
			if (lca==root) ans=ask(1);
			else {
				int tmp=getlca(root,lca);
				if (tmp==root || tmp!=lca) ans=ask(lca);
				else {
					int w=getson(root,lca);
					ans=ask(1)-ask(w);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

