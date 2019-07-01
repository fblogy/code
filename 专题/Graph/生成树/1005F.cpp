// 与1距离和最小生成树，就是bfs生成树 
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
int n, m, u, v, use[N], k,  d[N];
vector<pii> g[N];
vi fa[N], tmp;
queue<int> q;
vector<string> ans;
void dfs(int num) {
	if (num >= sz(tmp)) {
		string s;
		rep(i, 1, m+1) s += (use[i] + '0');
		ans.pb(s);
		if (sz(ans) >= k) {
			cout << k << endl;
			for (auto v: ans) cout << v << endl;
			exit(0);
		}
		return;
	}
	for (auto v : fa[tmp[num]]) {
		use[v] = 1;
		dfs(num+1);
		use[v] = 0;
	} 
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k;
	rep(i, 1, m+1) {
		cin >> u >> v;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	} 
	q.push(1);d[1] = 1;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (!d[v.fi]) {
				d[v.fi] = d[u] + 1;
				fa[v.fi].pb(v.se);
				q.push(v.fi);
			}else if (d[v.fi] == d[u] + 1) fa[v.fi].pb(v.se);
		}
	}
	rep(i, 2, n+1) if (sz(fa[i]) > 1) tmp.pb(i);else use[fa[i][0]] = 1;
	if (sz(tmp) == 0) {
		cout << 1 << endl;
		rep(i, 1, m+1) cout << use[i];
	}else {
		dfs(0);
		cout << sz(ans) << endl;
		for (auto v: ans) cout << v << endl; 
	}
	return 0;
}


