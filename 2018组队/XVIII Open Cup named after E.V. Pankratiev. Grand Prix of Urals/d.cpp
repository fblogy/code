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

const int N = 5e6 + 7;
int n, k, t, tt, ans, jc[N], inv[N];

int C(int n, int m) {
	return 1ll * jc[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
//	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	inv[N-1] = kpow(jc[N-1], P-2);
	per(i, 0, N-1) inv[i] = mul(inv[i+1], i+1);
	/*int ans2 = 0;
	rep(i, 0, 10)
		rep(j, 0, 10)
			rep(k, 0, 10) {
				if ((i - j)*2 + k == 0) ans2++;
			}
	de(ans2);*/
	if (n % 2 == 0) {
		cout << kpow(10, n / 2);
	}else {
		k = n / 2;
		rep(tt, 0, 5) {
			t = n / 4 * 9;
			//n / 2 % 2 == 1 ?  n / 4 * 9 + tt : 
			if (n / 2 % 2 == 1) t += tt;else t -= tt;
			rep(i, 0, k+1) {
				if (10 * i <= t) {
					int j = t - 10 * i;
					if (i & 1) ans = sub(ans, mul(C(k, i), C(k + j - 1, j)));
					else ans = add(ans, mul(C(k, i), C(k + j - 1, j)));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


