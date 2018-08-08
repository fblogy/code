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

int n,m,v,dep[N],fa[N],u,h[N],T,w,num,cnt[N][31][2];
pair<pii,int> edge[N*2];
vector<pii> g[N];
bool del[N*2];

bool cmp(pair<pii,int> a,pair<pii,int> b){return a.se>b.se;} 

void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi,pos=g[u][i].se;
		if (!del[pos]&&v!=1&&!fa[v]) {
			dep[v]=dep[u]+1;
			fa[v]=u;
			h[v]=pos;
			dfs(v);
		}
	}
}

int get(int x) {
	return x==fa[x] ? x : fa[x]=get(fa[x]);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(cas,0,T) {
		cin>>n>>m;
		rep(i,1,n+1) g[i].clear();
		rep(i,1,m+1) {
			cin>>u>>v>>w;
			edge[i]=mp(mp(u,v),w);
		}
		sort(edge+1,edge+m+1,cmp);
		rep(i,1,m+1) {
			u=edge[i].fi.fi;v=edge[i].fi.se;
			g[u].pb(mp(v,i));
			g[v].pb(mp(u,i));
		}
		rep(i,1,n+1) fa[i]=i;
		fill_n(del,m+1,0);
		rep(i,1,m+1) {
			u=edge[i].fi.fi;v=edge[i].fi.se;
			u=get(u);v=get(v);
			if (u==v) del[i]=1;
			else fa[u]=v;
		}
		fill_n(fa,n+1,0);
		dfs(1);
		rep(i,1,m+1) if (del[i]){
			u=edge[i].fi.fi;v=edge[i].fi.se;w=edge[i].se;
			while (u!=v) {
				if (dep[u]<dep[v]) swap(u,v);
				edge[h[u]].se+=w;
				u=fa[u];
			}
		}
		int mm=0;
		rep(i,1,m+1) if (!del[i]) edge[++mm]=edge[i];
		m=mm; 
		sort(edge+1,edge+m+1,cmp);
		rep(i,1,n+1) {
			fa[i]=i;
			rep(j,0,31) {
				cnt[i][j][1]=cnt[i][j][0]=0;
				if ((1<<j) & i) cnt[i][j][1]=1;else cnt[i][j][0]=1;
			}
		}
		ull ans=0;
		rep(i,1,m+1) {
			u=edge[i].fi.fi;v=edge[i].fi.se;w=edge[i].se;
			u=get(u);v=get(v);
			rep(j,0,31) {
				rep(k,0,2)
					rep(l,0,2)
						if (k^l^((w & (1<<j))>0)) ans+=(1ull<<j)*cnt[u][j][k]*cnt[v][j][l];
			}
			fa[v]=u;
			rep(j,0,31) rep(k,0,2) cnt[u][j][k]+=cnt[v][j][k]; 
		}
		cout<<ans<<endl;
	}
	return 0;
}

