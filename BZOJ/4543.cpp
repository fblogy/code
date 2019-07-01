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
struct LongChain{
	static const int N = 100005 , inf = ~0U>>1;
	int wson[N], top[N], dep[N], lg[N];
	int jump[N][20], id[N], who[N], rwho[N], _;
	int f[N], p[N], tid;
	vector<ll> h[N];
	ll ans;
	void dfs(int c, int fa, vi g[]){
		dep[c] = 1;int &s = wson[c] = top[c] = 0;
		jump[c][0] = fa;//rep(i, 1, 20) jump[c][i] = jump[jump[c][i-1]][i-1];
		rep(i, 0, sz(g[c])){
			int t = g[c][i];
			if (t != fa)
				dfs(t,c,g), dep[c] = max(dep[t]+1, dep[c]),(dep[t] >= dep[s])&&(s = t);
		}
	}
	void dfs2(int c, int fa, int rc, vi g[]){
		if(!top[c]) top[c] = c, rc = c;
		who[id[c]=++_]=c;rwho[_] = rc;
		int s = wson[c];
		if (s) top[s] = top[c], dfs2(s, c, jump[rc][0], g);
		rep(i, 0, sz(g[c])){
			int t = g[c][i]; 
			if (t != fa && t != s) dfs2(t, c, t, g);
		}
	}
	void Build(vi g[]){
		dfs(1, 0, g);_ = 0;dfs2(1, 0, 1, g);
		rep(i, 2, N) lg[i]=lg[i>>1]+1;
	}
	
	int id1(int x, int l) {assert(l >= 0 && l < dep[x]);if (l > dep[x]) return 0;return id[x] + l;}
	int id2(int x, int l) {assert(l >= 1 && l < dep[x]);return sz(h[p[x]]) - 1 - (dep[x] - 1) + l;}
	void solve(int c, int fa, vi g[]) {
		//de(id[c]);
		rep(i, 0, sz(g[c])){
			int t = g[c][i]; 
			if(t != fa) solve(t, c, g);
		}
		if(wson[c]) {
			p[c] = p[wson[c]];
			if (dep[wson[c]] > 1) ans += h[p[c]][id2(wson[c], 1)];
			h[p[c]].pb(0);
			h[p[c]].pb(0);
			f[id[c]] = 1;
			// upd c by wson[c], O(1) or O(log(n))
		} else {
			p[c] = ++tid;
			f[id[c]] = 1;
			h[tid].pb(0);
			// c is leaf
		}
		rep(i, 0, sz(g[c])){
			int t = g[c][i]; 
			if(t != fa && t != wson[c]) {
			// brute force upd c by t
			rep(l, 1, dep[t] + 1) 
				ans += h[p[c]][id2(c, l)] * f[id1(t, l-1)];
			rep(l, 1, dep[t])
			 	ans += h[p[t]][id2(t, l)] * f[id1(c, l-1)];
			rep(l, 1, dep[t] - 1) 
				h[p[c]][id2(c, l)] += h[p[t]][id2(t, l+1)];
			rep(l, 1, dep[t] + 1)
				h[p[c]][id2(c, l)] += f[id1(c, l)] * f[id1(t,l-1)];
			rep(l, 0, dep[t]) f[id[c] + l + 1] += f[id[t] + l];
			}
		}
		/*f[c][0] = 1;
		for (auto t : g[c]) if (t != fa) {
			solve(t, c, g);
			//ans += h[t][1];
			rep(l, 1, dep[c]) ans += h[c][l] * f[t][l-1] + h[t][l] * f[c][l-1];
			rep(l, 1, dep[c]) h[c][l] += h[t][l+1] + f[c][l] * f[t][l-1];
			rep(l, 1, dep[c]) f[c][l] += f[t][l - 1];
		}*/
		//de(c);
		//rep(l, 1, dep[c]+1) dd(h[c][l]);
		//cout << endl;
	}
	// kth_par should exist
	int kth_par(int x,int k){
		if(k==0) return x;
		int j0=1<<lg[k];
		int p0=jump[x][lg[k]];
		int j1=k-j0;
		int del=id[p0]-id[top[p0]];
		if(del>=j1) return who[id[p0]-j1];
		else return rwho[id[top[p0]]+j1-del];
	}
}hc;

const int N = 1e5 + 7;
int n, u, v;
vi g[N];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
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
	hc.Build(g);
	hc.solve(1, 0, g);
	cout << hc.ans << endl;
	return 0;
}


