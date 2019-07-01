// 仙人掌求两点之间有多少环 
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

const int N = 2e5 + 6;
vector<pii> g[N];
int w[N], n, m, cnt[N], u, v, ans, q;

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
    void dfs2(int u, int fa, int num) {
		num += (cnt[u] > 1);
		w[u] = num;
		for (auto v : bcc[u]) if (v != fa) {
			dfs2(v, u, num);
		}
	}
    
    int solve(int n,vector<pii> g[]){
        fill_n(dfn,n,_=0);
        fill_n(low,n,_st=0);
        fill_n(bcc,n,key=vi());
        rep(i,0,n) if(!dfn[i]) dfs(i,1,g);
        rep(i,0,n) for(auto j:g[i]) if(id[i]!=id[j.fi])
            bcc[id[i]].pb(id[j.fi]);
        rep(i, 0, n) cnt[id[i]]++;
        dfs2(0, -1, 0);
        return _;
    }
};

struct LCARMQ{
    static const int N = 101010 << 1;
    int a[20][N], lft[N], dep[N], lg[N], L;
    int rmin(int x, int y){ return dep[x] < dep[y] ? x : y;}
    void add(int x){ a[0][L++] = x;}
    void dfs(int c, int fa, const vi g[]){
        lft[c] = L; add(c);
        for(auto t : g[c]) if (t != fa) dep[t] = dep[c]+1, dfs(t, c, g), add(c);
    }
    void Build(const vi g[]){
        L = 0; dfs(0, -1, g);
        rep(i, 2, L) lg[i] = lg[i >> 1] + 1;
        rep(i, 1, 20){
            int lim = L + 1 - (1 << i);
            rep(j, 0, lim) a[i][j] = rmin(a[i-1][j], a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int i = lg[y-x+1];
        return rmin(a[i][x], a[i][y+1-(1<<i)]);
    }
} R;

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
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	BCC :: solve(n, g);
	R.Build(BCC :: bcc);
	cin >> q;
	rep(i, 1, q+1) {
		cin >> u >> v;
		u--; v--;
		u = BCC :: id[u];
		v = BCC :: id[v];
		int lca = R.lca(u, v);
		ans = w[u] + w[v] - 2 * w[lca] + (cnt[lca] > 1);
		ans = kpow(2, ans);
		cout << ans << endl;
	}
	return 0;
}


