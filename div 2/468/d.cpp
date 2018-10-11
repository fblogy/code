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

const int N = 100005;
const int mod = 1e9+7;

int n, ans, dep[N], cnt[N], u;
vi g[N];

void dfs(int u) {
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		dep[v] = dep[u] + 1;
		cnt[dep[v]] ^= 1;
		dfs(v);
	}
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 2, n+1) cin >> u, g[u].pb(i);
	dep[1] = 1;
	cnt[1] = 1;
	dfs(1);
	rep(i, 1, n+1) ans += cnt[i];
	cout << ans;
	return 0;
}

