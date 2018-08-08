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

const int N=5005;
const int mod=1e9+7;

int n,k,d,color[N],u,v,num,col;
ll ans;
bool f[N],vis[N],vis2[N];
vi g[N];
queue<int> q; 

void dfs(int u,int dep) {
	if (dep>=d) return;
	f[color[u]]=1;vis2[u]=1;
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if (color[v]&&!vis2[v]) {			
			dfs(v,dep+1);
		}
	}
}

ll bfs() {
	fill_n(vis,n+1,0);while (!q.empty()) q.pop();
	fill_n(color,n+1,0);
	vis[1]=1;q.push(1);
	ll res=1;
	while (!q.empty()) {
		u=q.front();q.pop();
		fill_n(f,k+1,0);
		fill_n(vis2,n+1,0);
		dfs(u,0);
		num=0;rep(i,1,k+1) if (f[i]) num++;else col=i;
 		color[u]=col;
 		//de(u);de(color[u]);de(num);
 		if (num==k) return 0;
 		res=res*(k-num)%mod;
		rep(i,0,sz(g[u])) {
			v=g[u][i];
			if (!vis[v]) {
				vis[v]=1;q.push(v);
			}
		}
	}
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>d;
	rep(i,1,n) {
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ans=bfs();
	d++;
	ans-=bfs();
	ans=(ans%mod+mod)%mod;
	cout<<ans;
	return 0;
}

