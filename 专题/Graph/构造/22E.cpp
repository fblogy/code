// 构造有向图加最少边转强连通 
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

const int N = 1e5 + 76;
int vis[N], fa[N];
vi w[N], tmp;
vector<pii> ans;
int n, m, a[N], du[N];

int dfs(int u) {
	if (vis[u]) {
		if (fa[u]) return fa[u];
		return fa[u] = u;
	}	
	vis[u] = 1;
	return fa[u] = dfs(a[u]); 
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i];
		du[a[i]]++;
	} 
	rep(i, 1, n+1) if (du[i] == 0) {
		int p = dfs(i); 
		w[p].pb(i);
	}
	rep(i, 1, n+1) if (sz(w[i])) w[i].pb(i); 
	rep(i, 1, n+1) if (!vis[i]) {
		int p = dfs(i);
		w[p].pb(p);
	}
	rep(i, 1, n+1) if (sz(w[i])) tmp.pb(i);
	if (sz(tmp) == 1 && sz(w[tmp[0]]) == 1) {
		cout << 0;
		return 0;
	}
	rep(i, 0, sz(tmp)-1) {
		ans.pb(mp(w[tmp[i]].back(), w[tmp[i+1]][0]));
	}
	rep(i, 0, sz(tmp)) {
		rep(j, (i != 0), sz(w[tmp[i]])-1 + (i == 0 && sz(w[tmp[i]]) == 1)) ans.pb(mp(w[tmp.back()].back(), w[tmp[i]][j]));
	}
	cout << sz(ans) << endl;
	for (auto v : ans) cout << v.fi << " " << v.se << endl;   
	return 0;
}


