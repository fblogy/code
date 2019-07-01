// 求1走到n和n走到1等长的最短路径，同一时刻两人不在同一点，最短路建模， 用分步走思想优化复杂度 
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
int n, m, u, v, d[505][505][2];
pair<pii, int> fa[505][505][2];
vi g[N];
pair<pii, int> now;
vector<pii> ans2;
int ans, len;
queue<pair<pii, int> > q;
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
	q.push(mp(mp(1, n), 0));d[1][n][0] = 1;
	while(!q.empty()) {
		auto t = q.front(); q.pop();
		int x = t.fi.fi, y = t.fi.se;
		if (t.se == 0) {
			for (auto u : g[x]) if (!d[u][y][1]) {
				d[u][y][1] = d[x][y][0] + 1;
				fa[u][y][1] = mp(mp(x, y), 0);
				q.push(mp(mp(u, y), 1));
			} 
		}else {
			for (auto v : g[y]) if (!d[x][v][0] && v != x) {
				d[x][v][0] = d[x][y][1];
				fa[x][v][0] = mp(mp(x, y), 1);
				q.push(mp(mp(x, v), 0));
				if (x == n && v == 1) {
					now = mp(mp(n, 1), 0);
					while (1) {
						if (now.se == 0) ans2.pb(now.fi);
						now = fa[now.fi.fi][now.fi.se][now.se];
						if(now.fi.fi == 0) break;
					}
					reverse(all(ans2));
					cout << sz(ans2)-1 << endl;
					for (auto v : ans2) cout << v.fi << " ";
					cout << endl;
					for (auto v : ans2) cout << v.se << " " ;
					return 0;
				}
			} 
		}
			
	}
	cout << -1;
	return 0;
}


