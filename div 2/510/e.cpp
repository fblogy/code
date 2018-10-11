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
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e6 + 7;
unordered_map<int, int> M;
int n, m, ax, ay, x, y, p[N], num;
ll f[N], cnt[N], w[N], sx[N], sy[N];
vector<pair<int, pii> > a;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1)
		rep(j, 1, m+1) {
			cin >> x;
			a.pb(mp(x, mp(i, j)));
		}
	cin >> ax >> ay;
	sort(all(a));
	rep(i, 0, sz(a)) if (M.count(a[i].fi)) p[i] = M[a[i].fi];else p[i] = M[a[i].fi] = ++num;
	
	rep(i, 0, sz(a)) {
		x = a[i].se.fi; y = a[i].se.se;
		if (p[i] == 1) f[i] = 0;
		else{
			f[i] = -2 * x * sx[p[i] - 1] - 2 * y * sy[p[i] - 1] + w[p[i]-1];
			f[i] %= P;
			if (f[i] < 0) f[i] += P;
			f[i] = mul(f[i], kpow(cnt[p[i]-1], P-2));
			f[i] = add(f[i], add(x * x, y * y));
		}
		cnt[p[i]]++;	
		w[p[i]] = add(w[p[i]], add(mul(x, x), mul(y, y)));
		w[p[i]] = add(w[p[i]], f[i]);
		sx[p[i]] = add(sx[p[i]], x);
		sy[p[i]] = add(sy[p[i]], y);
		if (p[i] > p[i-1]) {
			cnt[p[i]] += cnt[p[i] - 1];
			w[p[i]] = add(w[p[i]], w[p[i]-1]);
			sx[p[i]] = add(sx[p[i]], sx[p[i]-1]);
			sy[p[i]] = add(sy[p[i]], sy[p[i]-1]);
		}
		if (x == ax && y == ay) {
			cout << f[i];
			return 0;
		}
	}
	return 0;
}


