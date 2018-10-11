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
int ans, d[N], b[N];
vi a;
int f[N], n, k, u, v, w, st, ed, x, l, r, p;
pii h[N];
vector<pii> g[N];
bool use[N];
void dfs(int u, int fa) {
	for (auto v : g[u]) if (v.fi != fa){
		f[v.fi] = u;
		d[v.fi] = d[u] + v.se;
		dfs(v.fi, u);
	}
}

void dfs2(int u, int fa, int dep, int p) {
	b[p] = max(b[p], dep);
	for (auto v : g[u]) if (v.fi != fa && !use[v.fi]) {
		dfs2(v.fi, u, dep+v.se, p);
	}
}
 
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w}); 
	}
	dfs(1, 0);
	st = max_element(d + 1, d + n + 1) - d;
	d[st] = 0;f[st] = 0;dfs(st, 0);
	ed = max_element(d + 1, d + n + 1) - d;
	x = ed;
	while (1) {
		use[x] = 1;
		a.pb(x);
		x = f[x];
		if (x == 0) break;
	}
	reverse(all(a));
	rep(i, 0, sz(a)) dfs2(a[i], 0, 0, i);
	if (k >= sz(a)) cout << *max_element(b, b+sz(a));
	else {
		l = 0;r = -1;p = 0;ans = pw(30);
		rep(i, 0, sz(a) - k + 1) {
			while (l <= r && h[l].se < i) l++;
			while (p <= i + k - 1) {
				while (l <= r && h[r].fi <= b[p]) r--;
				h[++r] = {b[p], p};p++;
			}
			ans = min(ans, max(max(h[l].fi, d[a[i]]), d[a.back()] - d[a[p-1]]));
		}
		cout << ans;
	}
	return 0;
}


