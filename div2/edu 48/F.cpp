#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(a) a.size()
#define de(a) cout<<#a<<" = "<<a<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N=300005;
const int mod=1e9+7;

ll ma,mi[N],u,v,w,ww[N],fa[N],cnt,val[N],s[N],num,x;
int n,m,now;
bool vis[N],ok;
vector<pii> g[N];
vector<ll> z;
void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i].fi;
		if (v!=1&&fa[v]==0) {
			fa[v]=u;
			ww[v]=g[u][i].se;
			dfs(v);
		}
	}
}

int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;ok=1;
	rep(i,1,n) {
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	} 
	dfs(1);
	now=n;vis[1]=1;
	while (fa[now]) {
		num++;vis[now]=1;z.pb(ww[now]);
		now=fa[now];
	}
	rep(i,1,n+1) if (vis[i]){
		cnt++;
		int cnt2=0;val[i]=0;
		rep(j,0,sz(g[i])) {
			v=g[i][j].fi;
			if (!vis[v]) cnt++,cnt2++,val[i]=g[i][j].se;
		}
		if (cnt2>1) {ok=0;break;}
	}
	rep(i,1,num+1) s[i]=s[i-1]+z[sz(z)-i];
	if (cnt!=n) ok=0;
	if (ok==0) {
		rep(i,1,m+1) cout<<s[num]<<endl;
		return 0;
	}
	ma=-1ll<<60;now=n;mi[num+1]=1ll<<60;
	for(int i=num;i>=1;i--) {
		 mi[i]=min(mi[i+1],s[i]-val[now]);
		 if (val[now]||val[fa[now]]){
		 	ma=max(ma,s[i-1]+val[fa[now]]-mi[i]);
		 }
		 else ma=max(ma,s[i-1]+val[fa[now]]-mi[i+1]);
		 now=fa[now];
	}
	rep(i,1,m+1) {
		cin>>x;
		if (ma+x>=0) cout<<s[num];
		else cout<<s[num]+(ma+x);
		cout<<endl;
	}
	return 0;
}
