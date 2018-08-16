#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N = 200005;
const int mod = 998244353;

int ans, mi, res, sum, num, now, root, x, y, xx, yy, len1, len2, T, n, u, v, tmp, uu, vv, S;
bool vis[N], in[N], use[N], ok;
int f[N], fa[N], dep[N], dis[N], pos[N];
vector<pii> g[N];
pii edge[N];

void dfs(int u) {
	vis[u] = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi;
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			dis[v] = dis[u] + g[u][i].se;
			fa[v] = u;
			dfs(v);
			S += g[u][i].se;
		}
	}
} 

void dfs2(int u) {
	in[u] = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi;
		if (!in[v]) {
			mi += g[u][i].se;
			dfs2(v);
		}
	}
} 

void dfs3(int u) {
	vis[u] = 0;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi;
		if (vis[v]) {
			int tmp = S - dis[v] + dep[v] - dis[v];
			if (tmp == sum) res++;
			else if(tmp < sum) {
				sum = tmp; res = 1;
			}
			dfs3(v);
		}
	}
} 

int get(int x) {return x == f[x] ? x : f[x] = get(f[x]);}

int solve(int u) {
	S = 0;
	dfs(u);
	vi vt;
	if (pos[u]) {
		int x = edge[pos[u]].fi, y = edge[pos[u]].se;
		xx = x; yy= y;
		in[x] = in[y] = 1; 
		while (x != y) {
			if (dep[x] < dep[y]) swap(x, y);
			vt.pb(x);
			x = fa[x]; in[x] = 1;
		}
		vt.pb(x);
		len1 = dep[xx] - dep[x];
		len2 = dep[yy] - dep[x];
		num = len1 + len2 + 1;
		//assert(sz(vt) == num);
		//now = dis[xx] - dis[x] + len2 - (dis[yy] - dis[x]) + 1;
		now = dis[yy] - dis[x] + len1 - (dis[xx] - dis[x]);
		now = min(now, num - now);
		mi += now;
		if (now == num - now) res = 2; else res = 1;
		rep(i, 0, sz(vt)) dfs2(vt[i]);
		return res;
	}else {
		sum = S; res = 1;
		dfs3(u);
		mi += sum;
		return res;
	}
}

void init(){
	rep(i, 1, 2 * n + 1) f[i] = i;
	rep(i, 1, 2 * n + 1) g[i].clear();
	memset(use, 0, sizeof(use));
	memset(pos, 0, sizeof(pos));
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	memset(dis, 0, sizeof(dis));
	memset(dep, 0, sizeof(dep));
}

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		init();
		rep(i, 1, n+1) {
			cin >> u >> v;
			edge[i] = mp(u, v);
			uu = get(u); vv = get(v);
			if (uu != vv) {
				f[uu] = vv, use[i] = 1;
				g[u].pb(mp(v, 1));
				g[v].pb(mp(u, 0));
			}
		}
		ok = 1;
		rep(i, 1, n+1) if (!use[i]){
			u = edge[i].fi; v = edge[i].se;
			u = get(u);
			if (pos[u] == 0) {
				pos[u] = i;
			}else {ok = 0; break;}
		}
		mi = 0; ans = 1;
		if (!ok) {cout << -1 << " " << -1 << endl; continue;}
		rep(i, 1, 2 * n + 1) if (get(i) == i){
			ans = mul(ans, solve(i));
		}
		cout << mi << " " << ans << endl;
	} 
	return 0;
}

