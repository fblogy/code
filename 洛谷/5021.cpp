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
int n, mid, l, r, u, v, w, sum, m, ans;
vector<pii> g[N];
multiset<int> s;

int dfs(int u, int fa) {
	vi t;
	rep(i, 0, sz(g[u])) if (g[u][i].fi != fa){
		int x = dfs(g[u][i].fi, u) + g[u][i].se;
		if (x >= mid) sum++;else t.pb(x);
	}
	if (sz(t) == 0) return 0; 
	if (sz(t) == 1) return t[0];
	
	sort(all(t));
	int l1 = 0, r1 = sz(t) - 1, cnt = 0;
	while (r1 > l1) {
		while (l1 < r1  && t[l1] + t[r1] < mid) l1++;
		if (l1 >= r1) break;
		r1--;l1++;cnt++;
	}
	sum += cnt;
	if (cnt * 2 == sz(t)) return 0;
	int l = 0, r = sz(t) - 1, res = 0;
	while (l <= r) {
		int p = (l + r) >> 1;

		int l1 = 0, r1 = sz(t) - 1, x = 0;
		while (r1 > l1) {
			if (r1 == p) {r1--; continue;}
			while (l1 == p || (l1 < r1  && t[l1] + t[r1] < mid)) l1++;
			if (l1 >= r1) break;
			r1--;l1++;x++;
		}
			
		if (x == cnt) {
			res = t[p];
			l = p + 1;
		}else r = p - 1;
	}
	return res;
}

int main() {
	freopen("a.in","r",stdin);
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
		r += w;
	}
	while (l <= r) {
		mid = l + r >> 1;
		sum = 0;
		dfs(1, 0);
		if (sum >= m) {
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}


