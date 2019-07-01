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
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e5 + 7;
set<pii> s[N];
vi g[N];
int n, m, id[N], a[N], b[N], tid, u, v;
ll f[N];

pii operator - (pii a, pii b) {return {a.fi - b.fi, a.se - b.se};} 

ll cross(pii a, pii b) {
	db res = 1.0 * a.fi * b.se - 1.0 * a.se * b.fi;
	if (res >= 0) return 1;else return -1;
}

void ADD(int u, pii p){
    auto it = s[u].lower_bound(p);
    if (it != s[u].begin() && it != s[u].end()) {
		auto pre = --it;it++;
		if(cross((*it)-(*pre), p-(*pre)) >= 0) return;
	}
    s[u].insert(p);
    auto tmp = s[u].lower_bound(p);
	while (1) {
		if (tmp == s[u].begin()) break;
		auto p1 = --tmp;tmp++;if (p1 == s[u].begin()) break;
		auto p2 = --p1;p1++;
		if (cross(p - (*p2), (*p1) - (*p2)) >= 0) s[u].erase(p1);else break;
	}
    while (1) {
		if (tmp == (--s[u].end())) break;
		auto p1 = ++tmp;tmp--;if (p1 == (--s[u].end())) break;
		auto p2 = ++p1;p1--;
		if (cross((*p2) - p, (*p1) - p) >= 0) s[u].erase(p1);else break;
	}
	return;
}

int merge(int u, int v) {
	if (sz(s[u]) < sz(s[v])) swap(u, v);
	for (auto t : s[v]) ADD(u, t);
	s[v].clear();
	return u;
}

ll qry(int u, int k) {
	int l = -1e5, r = 1e5, mid;
	auto p = --s[u].end();
	while (l <= r) {
		mid = (l + r) >> 1;
		auto tmp = s[u].lower_bound({mid, -pw(60)});
		if (tmp == s[u].end() || tmp == (--s[u].end())) r = mid - 1;
		else {
			auto ne = ++tmp;tmp--;
			if ((*ne).se - (*tmp).se >= ((*ne).fi - (*tmp).fi) * k) p = tmp, r = mid - 1;
			else l = mid + 1;
		}
	}
	return (*p).fi * (-k) + (*p).se;
}

void dfs(int u, int fa) {
	for (auto v : g[u]) if (v != fa) {
		dfs(v, u);
		id[u] = id[v];
	} 
	if (id[u] == 0) {
		id[u] = ++tid;
		s[tid].insert({b[u], 0});
	}else {
		for (auto v : g[u]) if (v != fa) {
			if (id[u] != id[v]) id[u] = merge(id[u], id[v]);
		}
		f[u] = qry(id[u], -a[u]);
		ADD(id[u], {b[u], f[u]});
	}
}

int main() {
	freopen("a.in","r",stdin);
	freopen("f.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	rep(i, 1, n+1) cout << f[i] << " ";
	return 0;
}


