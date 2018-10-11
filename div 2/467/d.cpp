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

const int N = 100005;
const int mod = 1e9+7;

int n, m, k, u, v, o, s, vis[N][2], pre[N][2];
bool draw, win, in[N], f[N];
queue<pii> q;
vi g[N], ans;

void dfs(int u) {
	in[u] = 1; f[u] = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		if (!f[v]) {
			dfs(v);
		}else if (in[v]) draw = 1;
	}
	in[u] = 0;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> k;
		rep(j, 0, k) {
			cin >> v;
			g[i].pb(v);
		}
	}
	cin >> s;
	vis[s][0] = 1;
	q.push(mp(s,0));
	while (!q.empty()) {
		u = q.front().fi; o = q.front().se;
		q.pop();
		rep(i, 0, sz(g[u])) {
			v = g[u][i];
			if (!vis[v][o^1]) {
				vis[v][o^1] = 1;
				pre[v][o^1] = u;
				q.push(mp(v,o^1));
			}
		}
	}
	dfs(s);
	rep(i, 1, n+1) if (sz(g[i]) == 0 && vis[i][1]) win = 1, u = i, o = 1;
	if (win) {
		cout << "Win" << endl;
		while (u != s || o != 0) {
			ans.pb(u);
			u = pre[u][o];
			o ^= 1;
		}
		ans.pb(s);
		for (int i = sz(ans)-1; i >= 0; i--) cout << ans[i] << " "; 
	}else if (draw) cout << "Draw";
	else cout << "Lose";
	 
	return 0;
}

