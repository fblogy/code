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
const int N = 100005;
int n, x[N], y[N], p1, p2, p;
vector<pair<db, db> > V[2];
db ansx, ansy1, ansy2, lo, ro, m1, m2, s1, s2;

db Y (db x, int p, int o) {
	assert(p < sz(V[o]));
	if (p == 0) return V[o][0].se;
	if (V[o][p].fi != V[o][p-1].fi) {
		return V[o][p-1].se + (x - V[o][p-1].fi) * (V[o][p].se - V[o][p-1].se) / (V[o][p].fi - V[o][p-1].fi);
	}else return V[o][p].se;
}

db cal(db a, db b) {

	if (b >= x[p2]) return -pw(60);
	int t1 = lower_bound(all(V[0]), mp(a, 1.0 * pw(30))) - V[0].begin();
	int t2 = lower_bound(all(V[0]), mp(b, 1.0 * pw(30))) - V[0].begin();
	if (t1 == sz(V[0]) || t2 == sz(V[0])) return -pw(60);
	db ma = min(Y(a, t1, 0), Y(b, t2, 0));
	t1 = lower_bound(all(V[1]), mp(a, 1.0 * pw(30))) - V[1].begin();
	t2 = lower_bound(all(V[1]), mp(b, 1.0 * pw(30))) - V[1].begin();
	if (t1 == sz(V[1]) || t2 == sz(V[1])) return -pw(60);
	db mi = max(Y(a, t1, 1), Y(b, t2, 1));
	if (ma < mi) return -pw(60);
	ansy1 = mi; ansy2 = ma;
	return (b - a) * (ma - mi);
}

db solve(db w) {
	db lo = x[p1], ro = x[p2], s1, s2;
	rep(tim, 0, 100) {
		db m1 = (lo + lo + ro) / 3, m2 = (lo + ro + ro) / 3;
		s1 = cal(m1, m1 + w);
		s2 = cal(m2, m2 + w);
		//dd(m1);de(m2);dd(s1);de(s2);
		if (s1 < s2) lo = m1; else ro = m2;
	}
	ansx = lo; 
	return s1;
}

int main() {
	freopen("easy.in","r",stdin);
//	freopen("easy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> n;
	rep(i, 1, n+1) cin >> x[i] >> y[i];
	p1 = min_element(x+1, x+n+1) - x;
	p2 = max_element(x+1, x+n+1) - x;
	p = p1;
	while (p != p2) {
		V[0].pb(mp(x[p], y[p])); p++;
		if (p > n) p = 1;
	}
	V[0].pb(mp(x[p], y[p]));
	while (p != p1) {
		V[1].pb(mp(x[p], y[p])); p++;
		if (p > n) p = 1;
	}
	V[1].pb(mp(x[p], y[p]));
	reverse(all(V[1]));
	//de(solve(2));
	//return 0;
	lo = 0; ro = x[p2] - x[p1];
	rep(tim, 0, 100) {
		m1 = (lo + lo + ro) / 3; m2 = (lo + ro + ro) / 3;
		s1 = solve(m1);
		s2 = solve(m2);
		if (s1 < s2) lo = m1; else ro = m2;
	}
	cout << ansx << " "  << ansy1 << " " << ansx + lo << " " << ansy2;
	return 0;
}
