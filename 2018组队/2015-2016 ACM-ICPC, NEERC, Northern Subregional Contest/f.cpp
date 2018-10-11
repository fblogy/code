#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 25;
string s;
int F[N], fa[N],val[N], type[N], t[N], up[N];
ll x[N], y[N], ans[N];
int last[1005], pos[1005];
vi g[N];


void dfs(int u, int n) {
	if (type[u] == 3) { y[n]++; return;}
	int ma;
	if (type[u] == 2) ma = t[last[u]];
	if (type[u] == 1) ma = up[u];
	if (type[u] == 0) ma = n;
	rep(i, 0, ma) {
		t[u] = i;
		for (auto v : g[u]) dfs(v, n);
	}
	return;
}

template<class T>
struct polynomial{
	static const int N = 2005;
	T a1[N], b1[N], c[N], a[N];
	void calc(int n, T *a, T *b) {
		fill_n(c, n+1, 0);
		rep(i, 0, n+1)	rep(j, 0, 2) c[i+j] += a[i] * b[j];
		rep(i, 0, n+1)  a[i] = c[i];
	} 
	void solve(int n, T *x, T *y){ // a[0]*x^0 ... a[n]*x^n
		rep(i, 0, n+1) {
			T tmp = y[i];
			rep(j, 0, n+1) if (j != i) tmp /= (x[i] - x[j]);
			a1[0] = 1;
			rep(j, 0, n+1) if (j != i) {
				b1[0] = -x[j]; b1[1] = 1;
				calc(n, a1, b1);
			}
			rep(j, 0, n+1) a[j] += 1ll * a1[j] * tmp, a1[j] = 0;
		}
	}
};
polynomial<ll> poly;


int main() {
	freopen("a.in","r",stdin);
//	freopen("fygon.out","w",stdout);
	int cc = 0, now = 0;
	while(getline(cin, s)) {
		cc++;
		int f = 1, p = 0;
		while(s[p] == ' ') f++, p += 4;
		while(F[now] >= f) now = fa[now];
		fa[cc] = now; F[cc] = f;
		if(s[p] == 'l') type[cc] = 3;
		else {
			int var = s[p+4], rge = s[p+15];
			pos[var] = cc;
			if(isdigit(rge)) type[cc] = 1, up[cc] = rge - '0';
			else if (rge != 'n'){
				type[cc] = 2;
				last[cc] = pos[rge];
			}
		}
		now = cc;
	}
	type[0] = up[0] = 1;
	rep(i, 1, cc+1) g[fa[i]].pb(i);
	rep(i, 0, 7) dfs(0, i), y[i] *= 720, x[i] = i;
	poly.solve(6, x, y);
	rep(i, 0, 7) ans[i] = poly.a[i];
	int num = 0;
	rep(i, 0, 7) {
		if (ans[i] != 0) {
			num++;
			if (num != 1) {
				if (ans[i] > 0) cout << " + ";
				else cout << " - ", ans[i] = -ans[i];
			}else {
				if (ans[i] < 0) cout << " - ", ans[i] = - ans[i];
			}
			ll _g = __gcd(ans[i], 720ll);
			if (_g == 720) cout << ans[i] / 720;
			else cout << ans[i] / _g << "/" << 720 / _g << " ";
			rep(j, 0, i) cout << " * n";
		}
	}
	return 0;
}
