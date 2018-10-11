#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 505;
int n, m, p, use[N], must[N], op[N], s, t, x;
vi g[N], V0[2], V[N], ans;
int vis[N];
string S[N];

void dfs(int u, int d) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v]) {
		dfs(v, d ^ 1);
	}
  V0[d].pb(u);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> S[i];
		cin >> m;
		rep(j, 1, m+1) cin >> x, V[x].pb(i);
		V[i].pb(i);
	}
	rep(i, 1, n+1) {
		rep(j, 0, sz(V[i]))
			rep(k, j+1, sz(V[i]))
				if (S[V[i][j]] != S[V[i][k]]) {
					g[V[i][j]].pb(V[i][k]);
					g[V[i][k]].pb(V[i][j]);
				}
	}
	rep(i, 1, n+1) {
		sort(all(g[i]));
		g[i].erase(unique(all(g[i])), g[i].end());
	}
	rep(i, 1, n+1) if (!vis[i]) {
		V0[0].clear();
		V0[1].clear();
		dfs(i, 0);
		if (sz(V0[0]) < sz(V0[1])) {
			for (auto u : V0[0]) ans.pb(u);
		}else for (auto u : V0[1]) ans.pb(u);
 	}
	if (sz(ans) == 0) {
		cout << 1 << endl << 1 << endl;
	}else {
		cout << sz(ans) << endl;
		rep(i, 0, sz(ans)) cout << ans[i] << (i == sz(ans) - 1 ? "\n" : " ");
	}
	return 0;
}
