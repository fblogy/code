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
const db pi = acos(-1);
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
				w = 0; vi tmp;
				rep(j, 0, n) if (pw(j) & x) tmp.pb(a[j]), w += a[j];
				db hi = tmp.back(); tmp.pop_back();
				if (w <= hi * 2) continue;
				db ang = 0;
				for (auto v : tmp) ang += 2 * asin(db(v) / hi);
				bool out = (ang < pi);
				if (!out) {
					l = hi; r = 100000000;
					rep(tim, 0, 100) {
						mid = (l + r) / 2; ok = 1;
						for (auto v : tmp) if (mid <= v) {ok = 0; break;}
						if (!ok) {l = mid; continue;}
						db num = 2 * asin(hi / mid);
						for (auto v : tmp) num += 2 * asin(v / mid);
						if (num > 2 * pi) l = mid; else r = mid;
					}
				}else {
					l = hi; r = 100000000;
					rep(tim, 0, 100) {
						mid = (l + r) / 2; ok = 1;
						for (auto v : tmp) if (mid <= v) {ok = 0; break;}
						if (!ok) {l = mid; continue;}
						db num = -2 * asin(hi / mid);
						for (auto v : tmp) num += 2 * asin(v / mid);
						if (num < 0) l = mid; else r = mid;
					}
				}
				s = 0;
				for (auto v : tmp) s += sqrt(l * l / 4.0 - v * v / 4.0) * v / 2;
				if (out) s -= sqrt(l * l / 4.0 - hi * hi / 4.0) * hi / 2;
				else s += sqrt(l * l / 4.0 - hi * hi / 4.0) * hi / 2;
				ww[x] = s;
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


