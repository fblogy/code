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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

bool vis[N];
int f[N],du[N],n,m,x,y,ans;
vi g[N];

int DP(int x) {
	if (vis[x]) return f[x];
	vis[x]=1;f[x]=1;
	rep(i,0,sz(g[x])) {
		int y=g[x][i];
		if (du[y]>du[x])
		f[x]=max(f[x],DP(y)+1);
	}
	return f[x];
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);
		//du[x]++;du[y]++;
	}
	rep(i,0,n) {
		sort(g[i].begin(),g[i].end());
		du[i]=unique(g[i].begin(),g[i].end())-g[i].begin();
		du[i]++;
	}
	rep(i,0,n) ans=max(ans,DP(i));
	printf("%d",ans);
	return 0;
}
