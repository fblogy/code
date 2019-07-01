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

const int N = 3e5 + 7;
int jc[N], inv[N], n, n1, m1, ans, T;
ll m;
int C(int n, int m) {
	//if (n == m) return 1;
	if (m < 0 || m > n) return 0;
	return 1ll * jc[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	inv[N-1] = kpow(jc[N-1], P - 2);
	per(i, 0, N-1) inv[i] = mul(inv[i+1], i+1); 
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		if (m > n) {
			cout << 0 << endl;
			continue;
		}	
		if (m == n) {
			cout << mul(jc[n - 1], kpow(2, P - 2)) << endl;
			continue;
		}
		m = n - m;ans = 0;
		rep(i, 0, m) {
			n1 = n - i;
			m1 = m - i;
			ans = add(ans, mul(C(m, i), C(n1 - 1, m1 - 1)));
		}
		if (m == n) ans = add(ans, 1);
		ans = mul(ans, kpow(kpow(2, m), P - 2));
		ans = mul(ans, mul(jc[n], inv[m]));
		cout << ans << endl;
	}
	return 0;
}


