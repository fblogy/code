#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 3005;
const int mod = 1e9+7;

int n, m, k, u, v, w;

struct StoerWagner{
	static const int N = 305;
	static const int INF = 0x3f3f3f3f;;
	int n;
	int g[N][N], val[N];
	bool vis[N], use[N];
	void init(int _n) {
		n = _n;
		fill_n(use + 1, n, 0);
		rep(i, 1, n+1) fill_n(g[i] + 1, n, 0);
	}
	void add_edge(int u, int v, int w) {
    	g[u][v] += w;
    	g[v][u] += w;
	}
	void merge(int u, int v) {
    	rep(i, 1, n+1) {
			g[v][i] += g[u][i];
			g[i][v] += g[i][u];
		}
		use[u] = 1;
	}
	int MinimumCutPhase(int cnt, int &s, int &t) {
    	fill_n(val + 1, n, 0);
    	fill_n(vis + 1, n, 0);
    	t = 1;
    	while (--cnt) {
        	vis[s = t] = 1;
            rep(i, 1, n+1) if (!vis[i] && !use[i]) val[i] += g[t][i];
			int ma = 0;
			rep(i, 1, n+1) if (!vis[i] && !use[i] && val[i] >= ma) {
				ma = val[i]; t = i;
			}
            if (!ma) return 0;
    	}
    	return val[t];
	}
	int solve() {
    	int res = INF;
    	for (int i = n, s, t; i > 1; --i) {
        	res = min(res, MinimumCutPhase(i, s, t));
        	if (res == 0) break;
        	merge(s, t);
   		}
    	return res;
	}
} SW;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	while (cin >> n >> m >> k) {
		if (!n && !m && !k) break;
		//de(m);
		//return 0;
		SW.init(n);
		rep(i, 1, m+1) {
			cin >> u >> v >> w;
			SW.add_edge(u, v, w);
		}
		cout << SW.solve() << endl;
	}
	return 0;
}

