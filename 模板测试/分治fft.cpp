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
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

struct NTT{
	static const int M = 1 << 17 << 1, G = 3, P = ::P; //P = C*2^k + 1
	int N, na, nb, a[M], b[M], w[2][M], rev[M];
	ll kpow(ll a, int b){
		ll c = 1;
		for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
		return c;
	}
	void FFT(int *a, int f){
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
				for (int k = 0, l = 0, x, y; k < i; k++, l += t)
					x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
		if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
	}
	void work(){
		rep(i, 0, N){
			int x = i, y = 0;
			for (int k = 1; k < N; x>>=1, k<<=1) (y<<=1) |= x&1;
			rev[i] = y;
		}
		w[0][0] = w[1][0] = 1;
		for (int i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++)
			w[0][i] = (ll)x * w[0][i-1] % P, w[1][i] = (ll) y * w[1][i-1] % P;
	}
	void doit(int *a, int *b, int na, int nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, na, N) a[i] = 0;
		rep(i, nb, N) b[i] = 0;
		work(), FFT(a,0), FFT(b,0);
		rep(i, 0, N) a[i] = (ll)a[i] * b[i] % P;
		FFT(a, 1);
		//rep(i, 0, N) cout << a[i] << endl;
	}
} ntt;


const int N = 1 << 17 << 1;
int tmp1[N], tmp2[N], f[N], g[N], n;

void solve(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	solve(l, mid);
	rep(i, l, mid+1) tmp1[i-l] = f[i];
	rep(i, 0, r - l + 1) tmp2[i] = g[i];
	ntt.doit(tmp1, tmp2, mid - l + 1, r - l + 1);
	rep(i, mid+1, r+1) f[i] = add(f[i], tmp1[i - l]); 
	solve(mid+1, r);
}

int main() {
	int x = -1;
	de((1ll * x >> 60));
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n) cin >> g[i];
	f[0] = 1;
	solve(0, n - 1);
	rep(i, 0, n) cout << f[i] << " \n"[i == n - 1];
	return 0;
}

