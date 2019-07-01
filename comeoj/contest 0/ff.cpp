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
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef long double db;
typedef long double ld;
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

int T, n, a[20], S, w, ok, pre[1 << 12], p, now;
db l, r, mid, num, s, f[1 << 12], ans, ww[1 << 12];
const db PI = acos(-1);


ld solve_poly(vi &S) {
	assert(sz(S) > 0);
	int sum = 0, hi = S[0];
	vi vals;
	rep(i, 1, sz(S)) {
		int cur = S[i];
		if (cur > hi) swap(cur, hi);
		sum += cur;
		vals.pb(cur);
	}
	if (sum <= hi) return 0;
	auto getAngle = [&](ld D) -> ld{
		ld tot = 0;
		for (int l : vals) tot += 2 * asin(ld(l) / ld(D));
		return tot;
	};
	bool isReflex = (getAngle(hi) < PI);
	auto tooSmall = [&](ld D) {
		ld ang = getAngle(D);
		ld hiAng = 2 * asin(ld(hi) / ld(D));
		if (isReflex) return ang < hiAng;
		else return ang + hiAng >= 2 * PI;
	};
	ld mi = hi, ma = hi + 1;
	int numExpand = 0;
	while (tooSmall(ma)) {
		numExpand++;
		ma += (ma - mi);
	}
	rep(tim, 0, 50 + numExpand) {
		ld md = mi + (ma - mi) / 2;
		if (tooSmall(md)) mi = md;
		else ma = md;
	}
	ld D = mi, area = 0;
	for (int l : vals) {
		area += ld(l) * sqrt(ld(D) * ld(D) - ld(l) * ld(l)) / 4;
	}
	ld hiArea = ld(hi) * sqrt(ld(D) * ld(D) - ld(hi) * ld(hi)) / 4;
	if (isReflex) area -= hiArea;
	else area += hiArea;
	return area;
}


int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		sort(a, a+n);
		S = pw(n) - 1;
		rep(i, 0, S+1) f[i] = 0, ww[i] = 0;
		f[S] = 1;
		for (int x = S; x > 0; x = (x - 1) & S) {
				vi tmp;
				rep(j, 0, n) if (pw(j) & x) tmp.pb(a[j]);
				ww[x] = solve_poly(tmp);
		}
		ans = 0;
		now = S;
		per(i, 0, S+1) {
			if (i != S && ans < f[i]) ans = f[i], now = i;
			for (int x = i; x > 0; x = (x - 1) & i) {
				if (f[i ^ x] < f[i] * ww[x]) {
					f[i ^ x] = f[i] * ww[x];
					pre[i ^ x] = i;
				}
			}
		}
		cout << ans << endl;
		vector<vi> fang;
		while (now != S) {
			p = pre[now] ^ now;vi tmp;
			rep(i, 0, n) if (pw(i) & p) tmp.pb(a[i]);
			fang.pb(tmp);
			now = pre[now];
		}
		cout << sz(fang) << endl;
		for (auto v : fang) {
			cout << sz(v);
			for (auto u : v) cout << " " << u;
			cout << endl; 
		}
	}
	return 0;
}
