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

int fa[N],n,x,y,w;
vector<pii> g[N];
ll color[N],down[N],up[N],ans[N];

struct node{
	ll x,y;
	int i;
	node(ll x=0,ll y=0,int i=0):x(x),y(y),i(i){}
} a[N],h[N];

ll sqr(ll x) {return x*x;} 

bool cmp(node a,node b){if (a.x!=b.x) return a.x<b.x;return a.i<b.i;}

bool check1(node a,node b,ll w) {
	return 2*w*(a.x-b.x)<a.y-b.y;
}
bool check2(node a,node b,node c){
	return (c.y-b.y)*(b.x-a.x)<(b.y-a.y)*(c.x-b.x);
}

void solve(node a[],int n,bool o) {
	if (o==0) sort(a+1,a+n+1,cmp);else {
		rep(i,1,n+1) a[i].x=-a[i].x;
		rep(i,1,n/2+1) swap(a[i],a[n-i+1]);
	}
	int r=0;
	rep(i,1,n+1) {
		int v=a[i].i;
		while (r>1 && !check1(h[r],h[r-1],a[i].x)) r--;
		if (r>0) up[v]=max(up[v],sqr(color[h[r].i]-color[v])+down[h[r].i]);
		node tmp=node(a[i].x,a[i].y+sqr(a[i].x),a[i].i);
		while (r>1 && !check2(h[r-1],h[r],tmp)) r--;
		h[++r]=tmp;
	}
}

void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi;
		if (fa[v]==-1) {
			color[v]=g[u][i].se;
			fa[v]=u;
			dfs(v);
			down[u]=max(down[u],down[v]+sqr(color[u]-color[v]));
		}
	}
}

void dfs2(int u) {
	if (fa[u]!=0&&fa[fa[u]]!=0) {
		up[u]=max(up[u],up[fa[u]]+sqr(color[u]-color[fa[u]]));
	}
	int m=0;
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi;
		if (v!=fa[u]) {
			a[++m]=node(color[v],down[v],v);
		}
	}
	solve(a,m,0);
	solve(a,m,1);
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi;
		if (v!=fa[u]) dfs2(v);
	}
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n) {
		rep(i,1,n+1) g[i].clear();
		fill_n(down+1,n,0);fill_n(up+1,n,0);
		fill_n(ans+1,n,0);fill_n(fa+1,n,-1);
		rep(i,1,n) {
			cin>>x>>y>>w;
			g[x].pb(mp(y,w));
			g[y].pb(mp(x,w));
		}
		fa[1]=0;dfs(1);
		dfs2(1);
		rep(i,1,n+1) ans[fa[i]]=max(ans[fa[i]],down[i]);
		rep(i,1,n+1) ans[i]=max(ans[i],up[i]);
		//rep(i,1,n+1) cout<<down[i]<<endl;
		//rep(i,1,n+1) cout<<up[i]<<endl;
		//rep(i,1,n+1) cout<<max(up[i],down[i])<<endl;
		rep(i,1,n+1) cout<<ans[i]<<endl;
	}
	return 0;
}

