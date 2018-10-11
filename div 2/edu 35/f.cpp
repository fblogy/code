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
bool vis[N], in[N];
vi g[N];
int fa[N], dep[N], w, b, n, u, v, tmp, s, t, x;
ll sum;
vector<pii> ans;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v]) {
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

void dfs2(int u, int d) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v] && !in[v]){
		dfs2(v, d+1);
	}
	if (!in[u]) {
		sum += w + d;
		ans.pb({u, b});
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
	dep[1] = 1;
	dfs(1);
	tmp = 0;rep(i, 1, n+1) if (dep[i] > tmp) {tmp = dep[i];s = i;}
	memset(vis, 0, sizeof(vis));
	dep[s] = 1;
	dfs(s);
	tmp = 0;rep(i, 1, n+1) if (dep[i] > tmp) {tmp = dep[i];t = i;}
	x = t;
	while (1) {
		in[x] = 1;
		if (x == s) break;
		x = fa[x];
	}
	memset(vis, 0, sizeof(vis));
	rep(i, 1, n+1) if (in[i]) {
		b = (dep[i] - 1 > tmp - dep[i] ? s : t);
		w = max(dep[i] - 1, tmp - dep[i]);
		dfs2(i, 0);
	}
	x = t;
	while (1) {
		sum += --tmp;
		if (x == s) break;	
		ans.pb({x, s});
		x = fa[x];
	}
	cout << sum << endl;
	rep(i, 0, sz(ans)) {
		cout << ans[i].fi << " " << ans[i].se << " " << ans[i].fi << endl;
	}
	return 0;
}


