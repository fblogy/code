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
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
int P;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e5 + 7;
int n, a[N];
// a[l] ^ a[l+1] ^ a[l+2] ... ^ a[r] % mod 注意结果要再模mod 
map<int, int> M; 

int phi(int n) {
	if (M.count(n)) return M[n];
	int r = n, nn = n;
	for(int i = 2; i * i <= n; i++) if (n % i == 0){
		r = r / i * (i-1);
		while (n % i == 0) n /= i;
	}
	if (n > 1) r = r / n * (n-1);
	M[nn] = r;
	return r;
}

ll Euler_qpow(ll a, ll b, ll mod) {
	ll res = 1; bool ok = (b > 0 && a >= mod);
	while (b) {
		if (b & 1) {
			res = res * a;
			ok |= (res >= mod);
			res %= mod;			
		}
		a = a * a;
		ok |= (b > 1 && a >= mod);
		a %= mod;
		b >>= 1;
	}
	return res + mod * ok;
}

ll work(int l, int r, int mod) {
	if (mod == 1) return 1;
	if (l == r) return a[l];
	return Euler_qpow(a[l], work(l+1, r, phi(mod)), mod);
}

int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> P;
	rep(i, 1, n+1) cin >> a[i];
	cout << work(1, n, P);
	return 0;
}
