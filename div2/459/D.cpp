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

const int N=105;
const int mod=1e9+7;

int n,m,u,v;
char ch;
vector<pair<int,char> > g[N];
int f[N][N][200][2];

bool dfs(int x,int y,int w,int o) {
	if (f[x][y][w][o]!=-1) return f[x][y][w][o];
	bool ok=0;
	if (o==0) {
		rep(i,0,sz(g[x])) {
			int v=g[x][i].fi,w1=g[x][i].se;
			if (w1>=w) ok|=(dfs(v,y,w1,o^1)==0);
		}
	}else {
		rep(i,0,sz(g[y])) {
			int v=g[y][i].fi,w1=g[y][i].se;
			if (w1>=w) ok|=(dfs(x,v,w1,o^1)==0);
		}
	}
	return f[x][y][w][o]=ok;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,m+1) {
		cin>>u>>v>>ch;
		g[u].pb(mp(v,ch));
	}
	memset(f,-1,sizeof(f));
	rep(i,1,n+1) {
		rep(j,1,n+1) {
			if (dfs(i,j,0,0)) cout<<"A";else cout<<"B";
		}
		cout<<endl;
	}
	return 0;
}

