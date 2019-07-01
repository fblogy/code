// 给一个无向最大流的图定向 
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
vector<pair<pii, int> > g[N];
int w[N], s[N], d[N], use[N], n, m, v, u, p, op, ans[N];
queue<int> q;
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v >> w[i];
		g[u].pb(mp(mp(v, i), 0));
		g[v].pb(mp(mp(u, i), 1));
		s[u] += w[i];
		s[v] += w[i];
	}
	q.push(1);use[1] = 1;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (auto t : g[u]) {
			v = t.fi.fi, p = t.fi.se, op = t.se;
			if (use[v]) continue;
			d[v] += w[p];
			ans[p] = op;
			if (v != n && d[v] == s[v] / 2) {
				use[v] = 1;
				q.push(v);
			}
		}
	}
	rep(i, 1, m+1) cout << ans[i] << endl;
	return 0;
}


