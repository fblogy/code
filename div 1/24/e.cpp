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
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e5 + 7;
int n, p, x, v;
db ans, mi, l, r, mid;
vector<pii> a, b;

bool check(db mid) {
	p = sz(b) - 1;mi = pw(60);
	per(i, 0, sz(a)) {
		while (p >= 0 && b[p].fi >= a[i].fi) {
			mi = min(mi, b[p].fi - b[p].se * mid);
			p--;
		}
		if (a[i].fi + a[i].se * mid >= mi) return 1;
	}
	return 0;
}
int main() {
	//freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(11);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> x >> v;
		if (v > 0) a.pb(mp(x, v));
		else b.pb(mp(x, -v));
	}
	l = 0; r = 2e9;
	rep(cas, 0, 100) {
		mid = (l + r) / 2;
		if (check(mid)) r = mid;else l = mid;  
	}
	if (l > 1e9 + 7) cout << -1;else cout << l;
	return 0;
}


