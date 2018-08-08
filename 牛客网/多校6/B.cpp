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

const int N=52;
const int mod=998244353;

int f[N][N][N*(N+1)/2][2],g[2][N][N*(N+1)/2][2];
int n,ans,u,v,siz[N],fa[N],T,s,cnt,inv[N*(N+1)];
bool o;
vi to[N];

void add(int &x,int y) {
	x+=y;if (x>mod) x-=mod;
}

int mul(int x,int y) {
	return 1ll*x*y%mod;
}

int sub(int x,int y) {
	x-=y;if (x<0) x+=mod;
	return x;
}

void dfs(int u) {
	siz[u]=1;
	rep(i,0,sz(to[u])) {
		int v=to[u][i];
		if (v!=1&&!fa[v]) {
			fa[v]=u;
			dfs(v);
		}
	}
	memset(g,0,sizeof(g));
	g[0][1][1][0]=1;
	g[0][0][0][1]=1;
	o=0;
	rep(i,0,sz(to[u])) {
		int v=to[u][i];
		if (v!=fa[u]) {
			rep(j,0,siz[u]+1) 
				rep(k,0,siz[u]*(siz[u]+1)/2+1) 
					rep(l,0,2) {
						if (!g[o][j][k][l]) continue;
						rep(a,0,siz[v]+1)
							rep(b,0,siz[v]*(siz[v]+1)/2+1)
								rep(c,0,2) {
									if (!f[v][a][b][c]) continue;
									add(g[o^1][j>0 ? j+a : 0][k+b+j*a][l^c],mul(g[o][j][k][l],f[v][a][b][c])); 	
								}
					}	
			siz[u]+=siz[v];
			memset(g[o],0,sizeof(g[o]));
			o^=1;
		}
	}
	memcpy(f[u],g[o],sizeof(f[u]));
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	inv[1]=1;
	rep(i,2,50*(50+1)/2+1) inv[i]=mul(mod-mod/i,inv[mod%i]);  
	rep(cas,0,T) {
		cin>>n;
		rep(i,1,n+1) to[i].clear();
		rep(i,1,n) {
			cin>>u>>v;
			to[u].pb(v);
			to[v].pb(u);
		}
		//return 0;
		memset(fa,0,sizeof(fa));
		dfs(1);s=(n+1)*n/2;ans=0;
		rep(i,0,n+1)
			rep(j,0,n*(n+1)/2) {
				cnt=sub(f[1][i][j][1],f[1][i][j][0]);
				add(ans,mul(mul(cnt,s),inv[s-j]));
			}
		cout<<"Case #"<<cas+1<<": "<<ans<<endl;
	}
	return 0;
}

