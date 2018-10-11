#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e5 + 7;
int son[N], tid[N], dep[N], fa[N], siz[N], tim, top[N], n, m, u, v, k;
vector<pii> g[N];

namespace BCC{
    const int N = 202020;
    vi key , bcc[N];
    int dfn[N] , low[N] , id[N] , st[N] , _st , _;
    void dfs(int c,int dep,vector<pii> g[]){
        int cc=0;st[_st++]=c;
        dfn[c]=low[c]=dep;
        for(auto e:g[c]){
            int t=e.fi;
            if(!dfn[t]){
                dfs(t,dep+1,g);
                low[c]=min(low[c],low[t]);
                if(low[t]>dfn[c]) key.pb(e.se);
            } else if(dfn[t] != dfn[c] - 1 || cc++)
                low[c] = min(low[c] , dfn[t]);
        }
        if(low[c]==dfn[c]){
            do{id[st[--_st]]=_;}while(st[_st]!=c);
            _++;
        }
    }
    int solve(int n,vector<pii> g[]){
        fill_n(dfn,n,_=0);
        fill_n(low,n,_st=0);
        fill_n(bcc,n,key=vi());
        rep(i,0,n) if(!dfn[i]) dfs(i,1,g);
        rep(i, 0, n) id[i]++;
        rep(i,0,n) for(auto j:g[i]) if(id[i]!=id[j.fi])
            bcc[id[i]].pb(id[j.fi]);
        return _;
    }
};

void init(){
	memset(son,-1,sizeof(son));
	tim=0;
}
void dfs1(int u,int pre,int d){
    dep[u]=d;
    fa[u]=pre;
    siz[u]=1;
	for(auto v : BCC :: bcc[u]){
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    tid[u]=++tim;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
	for (auto v : BCC :: bcc[u]) {
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

int getlca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v;
		u--;v--;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}
	n = BCC :: solve(n, g);
	init();
	dfs1(1, 0, 1);
	dfs2(1, 1);
	cin >> k;
	rep(i, 0, k) {
		cin >> u >> v;
		u--; v--;
		u = BCC :: id[u]; v = BCC :: id[v];
		int x = getlca(u, v);
		cout << dep[u] + dep[v] - dep[x] * 2 << endl;
	}
	return 0;
}


