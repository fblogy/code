// 多重背包的二进制优化 
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

bool check(int x) {
	while (x) {
		if (x % 10 != 4  && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

const int N = 1e5 + 7;
int n, m, u, v, vis[N], cnt, a[N], f[N], ans;
vi g[N];

void dfs(int u) {
	vis[u] = 1;
	cnt++;
	for (auto v : g[u]) if (!vis[v]){
		dfs(v);
	}
}

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
	rep(i, 1, n+1) if (!vis[i]){
		cnt = 0;
		dfs(i);
		a[cnt]++;
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	rep(i, 1, n+1) if (a[i]){
		for (int k = 1; k <= a[i]; k <<= 1) {
			a[i] -= k;
			for (int j = n; j >= k * i; j--) f[j] = min(f[j], f[j - k * i] + k);
		}
		if (a[i]) for (int j = n; j >= a[i] * i; j--) f[j] = min(f[j], f[j - a[i] * i] + a[i]);
	}
	ans = pw(30);
	rep(i, 1, n+1) {
		if (check(i)) ans = min(ans, f[i]);
	}
	if (ans <= n + 10) cout << ans - 1; else cout << -1; 
	return 0;
}


