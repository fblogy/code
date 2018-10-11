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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e3 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e7 + 7;
const long double eps = 1e-8;
int q;
ll g[N], l, r, n;

bool check(ll x, int t, ll n) {
	ll res = 1;
	rep(i, 0, t) {
		n /= x;
		if (n == 0) return 0;
	}
	return 1;
}

ll cal(ll n) {
	if (n <= 1) return n;
	g[1] = n - 1;	
	rep(i, 2, 65) {
		g[i] = (ll)(pow((long double )n, (long double )1.0 / (long double)i));
		if (pow((long double)g[i]+1, (long double )i) <= n) g[i]++;
		/*ll l = 1, r = g[i-1]+1, mid;
		if (l == r) g[i] = 1;else {
			while (l <= r) {
				mid = (l + r) >> 1;
				if (check(mid, i, n)) {
					g[i] = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
		}*/
		g[i] --;
	}
	per(i, 1, 65) {
		for (int j = i + i; j <= 64; j += i) g[i] -= g[j];	
	}
	return n - g[1];
}
 
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> q;
	rep(cas, 0, q) {
		cin >> l >> r;
		cout << cal(r) - cal(l-1) << endl;
	}
	return 0;
}


