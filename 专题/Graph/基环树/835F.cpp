// 基环树断一条环边使直径最小 
// 分类讨论，处理选的两点在断掉一边和分在两边的情况 
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

const int N = 4e5 + 76;
int vis[N], use[N], fa[N], d[N], in[N], a[N], n, b[N], u, v, val[N];
ll  s[N], c[N], e[N], ans, w[N], f1[N], f2[N], ans2, t0[N], t1[N], ma;
vector<pair<pii, int> > g[N]; 
vi tmp1, tmp2;
map<pii, int> M;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v.fi.fi]){
		use[v.se] = 1;
		fa[v.fi.fi] = u;
		d[v.fi.fi] = d[u] + 1; 
		dfs(v.fi.fi);
	}
}

ll dfs2(int u, int fa) {
	ll res = 0;
	for (auto v : g[u]) if (!in[v.fi.fi] && v.fi.fi != fa) {
		ll tmp = dfs2(v.fi.fi, u) + v.fi.se;
		res = max(res, tmp);
		if (tmp>= f1[u]) {
			f2[u] = f1[u];
			f1[u] = tmp;
		}else if (tmp > f2[u]) f2[u] = tmp; 
	}
	ans2 = max(ans2, f1[u] + f2[u]);
	return res;
}


int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i] >> b[i] >> val[i];
		g[a[i]].pb(mp(mp(b[i], val[i]), i));
		g[b[i]].pb(mp(mp(a[i], val[i]), i));
		M[mp(a[i], b[i])] = M[mp(b[i], a[i])] = val[i];
	}
	dfs(1);
	rep(i, 1, n+1) if (!use[i]){
		u = a[i]; v = b[i];
		while (u != v) {
			if (d[u] >= d[v]) {
				tmp1.pb(u);
				u = fa[u];
			} else {
				tmp2.pb(v);
				v = fa[v];
			}
		}
		tmp1.pb(u);
		reverse(all(tmp2));
		for (auto v : tmp2) tmp1.pb(v);
		for (auto v : tmp1) in[v] = 1;
		rep(i, 0, sz(tmp1)) w[i] = dfs2(tmp1[i], -1);
		n = sz(tmp1);
		rep(i, 1, n) s[i] = s[i-1] + M[mp(tmp1[i], tmp1[i-1])];
		s[n] = s[n-1] + val[i]; 
		ma = 0;
		rep(i, 0, n) {
			c[i] = i == 0 ? w[0] : max(c[i-1], s[i] + w[i] + ma);
			ma = max(ma, w[i] - s[i]);
		}
		ma = 0;
		per(i, 0, n) {
			e[i] = i == n - 1 ? w[0] : max(e[i+1], ma + w[i] - s[i]);
			ma = max(ma, w[i] + s[i]);
		}
		rep(i, 0, n) t0[i] = i == 0 ? w[i] + s[i] : max(t0[i-1], w[i] + s[i]);
		per(i, 0, n) t1[i] = i == n - 1 ? w[i] + s[n] - s[i] : max(t1[i+1], w[i] + s[n] - s[i]);
		ans = pw(60);
		rep(i, 0, n) {
			ll tmp;
			tmp = i == 0 ? e[i] : max(max(c[i-1], e[i]), t0[i-1] + t1[i]);
			ans = min(ans, tmp);
		}
		cout << max(ans, ans2);
	}	
	return 0;
}


