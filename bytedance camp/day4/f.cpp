#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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

const int N = 1e5 + 7;
const int P = 1e9 + 7;

ll f[N][5], n, m, u, v, du[N], D[N], vis[N], x, cnt4[N], cnt3[N], t, ans;
priority_queue<pii> q;
vi tmp, w[N], gg[N], tmp2;
set<int> g[N];
void dfs(int u, int d, int fa) {
	if (d == 2) {
		tmp.pb(u);
		w[u].pb(fa);
		return;
	}
	if (d == 1) {
		tmp2.pb(u);vis[u] = 1;
	}
	for (auto v : g[u]) if (v != fa) {
		dfs(v, d+1, u);
	}
}

int main(){
//	freopen("a.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
		gg[u].pb(v);
		gg[v].pb(u);
		D[u]++;
		D[v]++;
		du[u]++;
		du[v]++;
	}
	rep(i, 1, n+1) q.push(mp(du[i], i));
	rep(i, 1, n+1) f[i][0] = 1;
	rep(i, 1, 5) rep(j, 1, n+1) for (auto v : g[j]) f[j][i] += f[v][i-1];

	while (!q.empty()) {
		while (!q.empty() && q.top().fi != du[q.top().se]) q.pop();
		if (q.empty()) break;
		x = q.top().se; q.pop();
		dfs(x, 0, 0);
		for (auto u : tmp) {
			//if(x == 5)de(u);
			for (auto v : w[u]) {
			//	if(x == 5)de(v);
				cnt4[v] += sz(w[u]) - 1;
				if (vis[u]) cnt3[v]++, t++;
			}	
			cnt4[x] += 1ll * sz(w[u]) * (sz(w[u]) - 1) / 2;
			cnt4[u] += 1ll * sz(w[u]) * (sz(w[u]) - 1) / 2;
			w[u].clear();
		}
		tmp.clear();
		for(auto u : tmp2) vis[u] = 0;
		tmp2.clear();
		cnt3[x] += t / 2;
		t = 0;
		for (auto u : g[x]) {
			du[u]--;
			q.push(mp(du[u], u));
			g[u].erase(x);
		}
	}
	//de(f[1][4]);
	rep(i, 1, n+1) {
		ans = f[i][4];
		ans -= cnt4[i] * 2;
		ans -= 2 * cnt3[i] * D[i];
		ans -= D[i] * f[i][2];
		for (auto v : gg[i]) ans -= (D[v] - 1) * D[v];
		ll ans3 = f[i][3] - D[i] * D[i] - 2 * cnt3[i];
		for (auto v : gg[i]) ans3 -= D[v] - 1, ans -= 2 * cnt3[v]; 
		cout << ans - ans3 + 4 * cnt3[i]<< endl;
	}
	return 0;
}

