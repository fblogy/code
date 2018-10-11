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

int n, m;

struct StoerWagner{
	static const int N = 3005, M = 100005 * 2, INF = 0x3f3f3f3f;;
	int head[N], val[N], e, n;
	int to[M], ne[M], data[M];
	bool vis[N];
	int fa[N], link[N];
	void init(int _n) {
		n = _n;
		fill_n(head + 1, n, -1);
		fill_n(link + 1, n, -1);
		rep(i, 1, n+1) fa[i] = i;
    	e = 0;
	}
	void add_edge(int u, int v, int w) {
    	to[e] = v; data[e] = w; ne[e] = head[u]; head[u] = e++;
    	to[e] = u; data[e] = w; ne[e] = head[v]; head[v] = e++;
	}
	int findset(int u) { 
    	return u == fa[u] ? u : fa[u] = findset(fa[u]);
	}
	void merge(int u, int v) {
    	int p = u;
    	while (~link[p]) p = link[p];
    	link[p] = v;
    	fa[v] = u;
	}
	int MinimumCutPhase(int cnt, int &s, int &t) {
    	fill_n(val + 1, n, 0);
    	fill_n(vis + 1, n, 0);
    	priority_queue<pii> q;
    	t = 1;
    	while (--cnt) {
        	vis[s = t] = 1;
        	for (int u = s; ~u; u = link[u]) {
            	for (int p = head[u]; ~p; p = ne[p]) {
                	int v = findset(to[p]);
                	if (!vis[v]) q.push(mp(val[v] += data[p], v));
            	}
        	}
        	while (!q.empty() && (vis[q.top().se] || val[q.top().se] != q.top().fi)) q.pop();
            if (q.empty()) return 0;
            t = q.top().se; q.pop();
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

int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
    while (cin >> n >> m) {
        SW.init(n);
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            SW.add_edge(u, v, w);
        }
        cout << SW.solve() << endl;
    }
}
