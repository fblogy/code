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

const int N = 1e6 + 7;
bool vis[N];
int use[N];
vi g[N];
int n, k, dep[N], u, v, du[N], root, ans;
vi V;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u])if (!vis[v]){
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

void dfs2(int u, int d) {
	use[u] = d;
	if (d == k) return;
	for(auto v : g[u]) if (use[v] == -1 || use[v] > d + 1){
		dfs2(v, d+1);
	}
}

bool cmp(int x, int y) {return dep[x] > dep[y];}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> u >> v;
		du[u]++;du[v]++;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i, 1, n+1) if (du[i] == 1) V.pb(i);else root = i;
	dfs(root);
	memset(use, -1, sizeof(use));
	sort(all(V), cmp);
	rep(i, 0, sz(V)) {
		if (use[V[i]] == -1) {
			ans++;
			dfs2(V[i], 0);
		}
	}
	cout << ans;
	return 0;
}


