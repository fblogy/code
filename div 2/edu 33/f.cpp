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
const int M = 50;
int root[N], dep[N], tr[N * M], ls[N * M], rs[N * M], tid, n, m, T, a[N], u, v, p, q, Root;
vi g[N];
bool vis[N];

int merge(int x, int y, int l, int r) {
	int mid = (l + r) >> 1;
	tr[++tid] = min(tr[x], tr[y]);
	int now = tid;
	if (l == r) return now;
	if (ls[x] && ls[y]) {
		ls[now] = merge(ls[x], ls[y], l, mid);
	}else if (ls[y]) ls[now] = ls[y];
	else if (ls[x]) ls[now] = ls[x];
	if (rs[x] && rs[y]) {
		rs[now] = merge(rs[x], rs[y], mid+1, r);
	}else if (rs[y]) rs[now] = rs[y];
	else if (rs[x]) rs[now] = rs[x];
	return now; 
}

int ne(int x, int l, int r){
	tr[++tid] = a[x];
	int now = tid;
	if (l == r && l == dep[x]) return now;
	int mid = l + r >> 1;
	if (dep[x] <= mid) ls[now] = ne(x, l, mid);
	else rs[now] = ne(x, mid+1, r);
	return now;
}

int qry(int L, int R, int l, int r, int now) {
	if (L <= l && r <= R) {
		return tr[now];
	}
	int res = pw(30), mid = (l + r) >> 1;
	if (ls[now] && L <= mid) res = min(res, qry(L, R, l, mid, ls[now]));
	if (rs[now] && R > mid) res = min(res, qry(L, R, mid+1, r, rs[now]));
	return res;
}

void dfs(int u) {
	vis[u] = 1;
	root[u] = ne(u, 1, n);
	tr[root[u]] = a[u];
	for (auto v : g[u]) if (!vis[v]) {
		dep[v] = dep[u] + 1;
		dfs(v);
		root[u] = merge(root[u], root[v], 1, n);
	}
}

int main() {
//	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> Root;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dep[Root] = 1;
	dfs(Root);
	cin >> T;
	int pre = 0;
	rep(cas, 0, T) {
		cin >> p >> q;
		p = (p + pre) % n + 1;
		q = (q + pre) % n;
		pre = qry(1, min(dep[p] + q, n), 1, n, root[p]);
		cout << pre << endl;
	}
	return 0;
}


