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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 3e5 + 7;
int u, v, n, cnt, col[N], id[N], num, m, st;
pair<ull, int> x;
map<pair<ull, int>, int> s;
vi g[N], gg[N];

pair<ull, int> gethash(int i) {
	ull res1 = 0; int res2 = 0;
	for (auto u : g[i]) {
		res1 = res1 * (n + 2) + u;
		res2 = add(mul(res2, n+1) , u); 
	}
	return mp(res1, res2);
}

void dfs(int u) {
	col[u] = ++num; 
	for(auto v : gg[u]) if (!col[v]) dfs(v);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i, 1, n+1) {
		g[i].pb(i);
		sort(all(g[i]));
		x = gethash(i);
		id[i] = s.count(x) ? s[x] : s[x] = ++cnt; 
	}
	rep(i, 1, n+1) 
		for (auto v : g[i]) 
			if (id[i] != id[v]) gg[id[i]].pb(id[v]);
	rep(i, 1, cnt+1) {
		sort(all(gg[i]));
		gg[i].erase(unique(all(gg[i])), gg[i].end());
		if (sz(gg[i]) > 2) {cout << "NO"; return 0;}
		if (sz(gg[i]) < 2) st = i;
	}
	dfs(st);
	if (num == cnt) {
		cout << "YES" << endl;
		rep(i, 1, n+1) cout << col[id[i]] << " ";
	}else cout << "NO";
	return 0;
}


