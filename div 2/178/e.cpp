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

const int N = 5e3 + 7;
int n, m, S, u, v, w;
ll ans, sum, tmp, w1, w2;
int siz[N];
pair<pii, int> edge[N];
vector<pii> g[N];
bool vis[N];

void dfs(int u, int x) {
	siz[u] = 1;vis[u] = 1;
	for (auto v : g[u]) {
		if (v.fi == x || vis[v.fi]) continue;
		dfs(v.fi, x);
		siz[u] += siz[v.fi];
		sum += 1ll * v.se * siz[v.fi];
	}
}

void dfs2(int u, int x, int S) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (v.fi == x || vis[v.fi]) continue;
		if (siz[v.fi] > S - siz[v.fi]) {
			sum += 1ll * v.se * (S - 2 * siz[v.fi]);
			dfs2(v.fi, x, S);
			return;
		}
	}
}

void dfs3(int u, int x, int S) {
	vis[u] = 0;
	for (auto v : g[u]) {
		if (v.fi == x || vis[v.fi] == 0) continue;
		tmp += 1ll * (S - siz[v.fi]) * (siz[v.fi]) * v.se;
		dfs3(v.fi, x, S);
	}
}

ll work(int u, int v) {
	sum = 0;
	dfs(u, v);
	dfs3(u, v, siz[u]);
	dfs2(u, v, siz[u]);
	return sum;
}


void solve(int u, int v, int w) {
	tmp = 0;
	fill_n(vis, n+1, 0);
	fill_n(siz, n+1, 0);
	w1 = work(u, v);
	w2 = work(v, u);
	ans = min(ans, tmp + 1ll * siz[u] * siz[v] * w + siz[v] * w1 + siz[u] * w2);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n) {
		cin >> u >> v >> w;
		edge[i] = {{u, v}, w};
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	ans = pw(60);
	rep(i, 1, n) solve(edge[i].fi.fi, edge[i].fi.se, edge[i].se);
	cout << ans;
	return 0;
}


