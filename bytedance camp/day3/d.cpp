#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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

const int N = 1e5 + 7;
const int P = 1e9 + 7;

vector<pii> g[N];
vi gg[N];
int vis[N], u, v, n, m, k, ans[N], a[N], b[N], now, ok[1005][1005];
void dfs(int u){
    for (auto v : g[u]) if (!vis[v.se]){
        vis[v.se] = 1;
        dfs(v.fi);
        ans[++k] = v.se;
    }
}

namespace MaxMatch{
    const int N = 5050;
    int link[N],vis[N];
    int dfs(int c,vi g[]){
        for(auto t : g[c])
            if(!vis[t]){
                vis[t] = true;
                if(link[t]==-1||dfs(link[t],g))
                    return link[t]=c,1;
            }
        return 0;
    }
    int solve(int n,int m,vi g[]){
        fill_n(link,m+1,-1);
        int ret=0;
        rep(i,1,n+1){
            memset(vis,0,(m+1)*sizeof(int));
            ret += dfs(i,g);
        }
        return ret;
    }
}

int main(){
	//freopen("a.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if (m == 0) {cout << "Impossible";return 0;}
	rep(i, 1, m+1) {
		cin >> a[i] >> b[i];
		u = a[i], v = b[i];
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
		ok[u][v] = 1;
	}
	dfs(1);
	now = 1;
	rep(i, 1, k+1) {
		//cout << ans[i] << endl;
		if (now != a[ans[i]]) swap(a[ans[i]], b[ans[i]]);
		now = b[ans[i]];
		gg[a[ans[i]]].pb(b[ans[i]]);
		//gg[b[ans[i]]].pb(a[ans[i]]);
	}
	//for (auto t : gg[]) de(t);
	int an = MaxMatch :: solve(n, n, gg);
	//assert(an == n);
	if (an < n) {
		cout << "Impossible";return 0;
	}
	cout << n << endl;
	rep(i, 1, n+1) {
		u = i;
		v = MaxMatch :: link[i];
		if (!ok[u][v]) swap(u, v);
		//assert(ok[u][v]);
		cout << u << " " << v << endl;
	}
	return 0;
}

