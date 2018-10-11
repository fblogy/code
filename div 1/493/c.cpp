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
int kpow(int a, ll b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e6 + 7;
int jc[N], inv[N], n, ans, tmp;

int C(int n, int m) {
	if (n < m) return 0;
	return mul(mul(jc[n], inv[m]), inv[n - m]);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	jc[0] = 1;
	rep(i, 1, n+1) jc[i] = mul(jc[i-1], i);
	inv[n] = kpow(jc[n], P - 2);
	per(i, 0, n) inv[i] = mul(inv[i+1], i+1); 
	rep(i, 0, n+1)  {
		tmp = kpow(kpow(3, n-i) - 1, n);
		tmp = mul(tmp, C(n, i));
		if (i & 1) ans = add(ans, tmp);else ans = sub(ans, tmp);
	}
	rep(i, 0, n+1) {
		tmp = kpow(3, 1ll * n * (n - i));
		tmp = mul(tmp, 2 * C(n, i));
		if (i & 1) ans = sub(ans, tmp);else ans = add(ans, tmp);
	}
	ans = sub(ans, kpow(3, 1ll * n * n));
	ans = mul(ans, 3);
	rep(i, 1, n+1) {
		tmp = kpow(3, 1ll * n * (n - i) + i);
		tmp = mul(tmp, 2 * C(n, i));
		if (i & 1) ans = add(ans, tmp);else ans = sub(ans, tmp);
	}
	cout << ans;
	return 0;
}


