// dfs序判断父子关系，dsu维护当前祖先 

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

int d[N], tim, k, l[N], r[N], dfnl[N], dfnr[N], f[N], u, v, n, m, op, t, ok;
vi g[N];
vector<pii> q;

int get(int x) {
	if (x == f[x]) return x;
	return f[x] = get(f[x]);
}

void dfs(int u, int fa) {
	dfnl[u] = ++tim;
	for (auto v : g[u]) if (v != fa) {
		dfs(v, u);
	}
	dfnr[u] = ++tim;
}

bool check(int u, int v) {
	return dfnl[v] >= dfnl[u] && dfnr[v] <= dfnr[u];
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) f[i] = i;
	rep(i, 1, m+1) {
		cin >> op;
		if (op == 1) {
			cin >> u >> v;
			f[u] = v;
			g[v].pb(u);
			d[u]++;
		}else if (op == 2) {
			cin >> u; k++;
			l[k] = u;
			r[k] = get(u);
		}else {
			cin >> u >> t;
			q.pb(mp(u, t));
		}
	}
	rep(i, 1, n+1) if (d[i] == 0) dfs(i, 0);
	for (auto t : q) {
		u = t.fi; v = t.se;
		ok = 0;
		if (get(u) == get(l[v])) {
			ok = check(u, l[v]) & check(r[v], u);
		}
		if (ok) cout << "YES";else cout << "NO";
		cout << endl;
	}
	return 0;
}


