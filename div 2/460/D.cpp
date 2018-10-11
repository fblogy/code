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

const int N=300005;
const int mod=1e9+7;

int dp[N][26],n,m,ans,u,v,du[N];
vi g[N];
bool vis[N];
string s;
queue<int> q;

void dfs(int u) {
	if (vis[u]) return;
	vis[u]=1;
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if (!vis[v]) dfs(v);
		rep(j,0,26) dp[u][j]=max(dp[u][j],dp[v][j]);
	}
	dp[u][s[u-1]-'a']++;
	return;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	rep(i,1,m+1) {
		cin>>u>>v;
		g[u].pb(v);
		du[v]++;
	}
	rep(i,1,n+1) if (du[i]==0) q.push(i);
	while (!q.empty()) {
		u=q.front();q.pop();
		rep(i,0,sz(g[u])) {
			v=g[u][i];
			du[v]--;
			if (du[v]==0) q.push(v);
		}
	}
	rep(i,1,n+1) if (du[i]!=0) {cout<<-1;return 0;}
	rep(i,1,n+1) if (!vis[i]) dfs(i);
	rep(i,1,n+1) rep(j,0,26) ans=max(ans,dp[i][j]); 
	cout<<ans;
	return 0;
}

