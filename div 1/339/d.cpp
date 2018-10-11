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

// N is 2 size of tree , id of nodes start from 0
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
        L = 0; dfs(1, -1, g);
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

const int N = 1e5 + 7;
int n, u, v, q, k, x;
vi g[N];
bool imp[N];

bool cmp(int a, int b) {
	return R.lft[a] < R.lft[b];
}

namespace Vtree{// some nodes remain
    const int N = 101010;
    int tp[N], _, f[N], rem[N];
    vi g[N];// nodes sorted in dfs order
    bool ok;
    void dfs(int c, int fa) {
		for (auto t : g[c]) if (t != fa){ 
			dfs(t, c);
			f[c] += f[t];
			if (imp[c]) {
				if (imp[t] && R.dep[t] == R.dep[c] + 1) ok = 0;
				if (rem[t]) f[c]++;
			}else if (rem[t]) rem[c]++;
		}
		if (imp[c]) rem[c] = 1;
		else if (rem[c] > 1) rem[c] = 0, f[c]++;
	}
    
    int solve(vi &v, LCARMQ &R){
        _ = 0;ok = 1;
        vi del; del.pb(tp[_++] = v[0]);
        rep(i, 1, sz(v)){
            int lca = R.lca(tp[_-1], v[i]);
            vi l;while(_ > 0 && R.dep[lca] < R.dep[tp[_-1]]) l.pb(tp[--_]);
            if(_ == 0 || lca != tp[_-1]) del.pb(tp[_++] = lca);
            l.pb(tp[_-1]);del.pb(tp[_++] = v[i]);
            rep(i, 1, sz(l)) g[l[i]].pb(l[i-1]);
        }
        rep(i, 0, _-1) g[tp[i]].pb(tp[i+1]);
        sort(all(del), cmp);
        dfs(del[0], -1);
		// dfs()
		int res = f[del[0]];
		for(auto t : del){
            // Cal()
            f[t] = rem[t] = 0;
            g[t].clear();
        }
        if (ok) return res;
        return -1;
    }
}


int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	R.Build(g);
	cin >> q;
	rep(i, 0, q) {
		cin >> k;
		vi v;
		rep(j, 0, k) cin >> x, v.pb(x), imp[x] = 1;
		sort(all(v), cmp);
		cout << Vtree :: solve(v, R) << endl;
		rep(j, 0, k) imp[v[j]] = 0;
	}
	return 0;
}


