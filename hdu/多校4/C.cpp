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

int f1[N],f2[N],fa[N],dep[N],prob[N],siz1[N],siz2[N],ans1,ans2,T,n,q,u,v,w,st,ed;
vector<pii> g[N];

int get1(int x) {
	if (x==f1[x])  return f1[x];
	return f1[x]=get1(f1[x]);
}

int get2(int x) {
	if (x==f2[x])  return f2[x];
	return f2[x]=get2(f2[x]);
}

void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi,w=g[u][i].se;
		if (v!=fa[u]) {
			dep[v]=dep[u]+1;
			fa[v]=u;prob[v]=w;
			dfs(v);
			if (w<3)  { f1[v]=u; siz1[u]+=siz1[v];}
			if (w==1) { f2[v]=u; siz2[u]+=siz2[v];}
		}
	}
	if (prob[u]==3) { siz2[fa[u]]+=siz1[u];}
}

void uni1(int u,int v) {
	u=get1(u);v=get1(v);
	if (dep[u]>dep[v]) swap(u,v);
	f1[v]=u;siz1[u]+=siz1[v];
	siz2[get2(fa[u])]+=siz1[v];
} 

void uni2(int u,int v){
	u=get2(u);v=get2(v);
	if (dep[u]>dep[v]) swap(u,v);
	f2[v]=u;siz2[u]+=siz2[v];
}

void init(){
	rep(i,1,n+1) siz1[i]=1,siz2[i]=0,fa[i]=0;
	rep(i,1,n+1) f1[i]=f2[i]=i,g[i].clear();
} 

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(cas,0,T) {
		cin>>n>>q;
		init();
		rep(i,1,n) {
			cin>>u>>v>>w;
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
		}
		dfs(1);
		rep(i,1,q+1) {
			cin>>u>>v>>st>>ed;
			if (dep[u]<dep[v]) swap(u,v);
			if (prob[u]==2) {
				prob[u]--;uni2(u,v);
			}else if (prob[u]==3){
				prob[u]--;uni1(u,v);
				siz2[get2(v)]-=siz1[u];
			}
			ans1=0;
			if (get1(st)==get1(ed)) ans1=1;
			if (get2(fa[get1(ed)])==get2(st)) ans1=1;
			if (get1(fa[get2(st)])==get1(ed)) ans1=1;
			ans2=siz1[get1(st)];
			st=get2(st);
			ans2+=siz2[st]+((fa[st]==0||prob[st]!=3)?0:siz1[get1(fa[st])]);
			cout<<ans1<<" "<<ans2<<endl;
		}
	}
	return 0;
}

