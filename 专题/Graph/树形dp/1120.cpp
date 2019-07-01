// 树上选一个点集，叶子节点是点集中其父亲的线性组合，使所有叶子线性无关，要代价最小 
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

const int N = 2e5 + 7;
ll f[N][2];
int n, m, u, v, du[N], a[N], vis[N][2], use[N], cnt;
vi g[N];
void dfs(int u, int fa) {
	if (u != 1 && du[u] == 1) {
		f[u][0] = a[u];
		f[u][1] = 0;
		return;
	}
	ll res = 0;
	for (auto v : g[u]) if (v != fa){
		dfs(v, u);
		res += f[v][0];
	}
	f[u][0] = res;
	f[u][1] = pw(60);
	for (auto v : g[u]) if (v != fa) f[u][1] = min(f[u][1], res - f[v][0] + f[v][1]), f[u][0] = min(f[u][0], res - f[v][0] + f[v][1] + a[u]);
}

void dfs2(int u, int op, int fa) {
	if (vis[u][op]) return;
	vis[u][op] = 1;
	if (u != 1 && du[u] == 1) {
		if (op == 0) use[u] = 1;
		return;
	}
	ll res = 0;
	for (auto v : g[u]) if (v != fa) res += f[v][0];
	vi tmp;
	if (op == 0) {
		if (f[u][0] == res) for (auto v : g[u]) if (v != fa) dfs2(v, 0, u);
		for (auto v : g[u]) if (v != fa && f[u][0] == res - f[v][0] + f[v][1] + a[u]) {
			use[u] = 1;
			tmp.pb(v);	
		}
		if (sz(tmp) == 0) return;
		for (auto v : tmp) dfs2(v, 1, u);
		if (sz(tmp) >= 2) {for (auto v : g[u]) if (v != fa) dfs2(v, 0, u);}
		else for (auto v : g[u]) if (v != fa && v != tmp[0]) dfs2(v, 0, u);
		
	}else {
		for (auto v : g[u]) if (v != fa && f[u][1] == res - f[v][0] + f[v][1]) tmp.pb(v);
		for (auto v : tmp) dfs2(v, 1, u);
		if (sz(tmp) >= 2) {for (auto v : g[u]) if (v != fa) dfs2(v, 0, u);}
		else for (auto v : g[u]) if (v != fa && v != tmp[0]) dfs2(v, 0, u);
	}
	return;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		du[u]++;
		du[v]++;
	}
	dfs(1, -1);
	
	dfs2(1, 0, -1);
	rep(i, 1, n+1) if (use[i]) cnt++;
	cout << f[1][0] << " " << cnt << endl;
	rep(i, 1, n+1) if (use[i]) cout << i << " "; 
	return 0;
}


