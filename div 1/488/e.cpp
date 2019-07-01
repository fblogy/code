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


const int M = 1<<18;
const db pi = acos(-1);

struct vir{
	db re, im;
	vir(db r = 0.0, db i = 0.0) {re = r, im = i;}
	void print() {printf("%lf %lf\n", re, im);}
} r[M*2], l[M*2], W[2][M*2];

vir operator +(const vir&A,const vir&B) {return vir(A.re+B.re,A.im+B.im);}
vir operator -(const vir&A,const vir&B) {return vir(A.re-B.re,A.im-B.im);}
vir operator *(const vir&A,const vir&B) {return vir(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}

struct FFT{
	int N, na, nb, rev[M*2];
	inline void fft(vir *a, int f){
		vir x, y;
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N/(i<<1); j < N; j += i<<1)
				for (int k = 0, l = 0; k < i; k++, l += t) 
					x = W[f][l] * a[j+k+i], y = a[j+k], a[j+k] = y+x, a[j+k+i] = y-x;
		if (f) rep(i, 0, N) a[i].re /= N;
	}
	inline void work(){
		rep(i, 0, N){
			int x = i, y = 0;
			for (int k = 1; k < N; x >>= 1, k <<= 1) (y<<=1)|=x&1;
			rev[i] = y;
		}
		rep(i, 0, N) {
			W[0][i] = vir(cos(2*pi*i/N), sin(2*pi*i/N));
			W[1][i] = vir(cos(2*pi*i/N), -sin(2*pi*i/N));
		}
	}	
	inline void doit(vir *a, vir *b, int na, int nb){
		for (N = 1; N < na || N < nb; N <<= 1); N <<= 1;
		work(), fft(a, 0), fft(b, 0);
		rep(i, 0, N) a[i] = a[i]*b[i];
		fft(a, 1);
		//rep(i, 0, N) a[i].print();
	}
} fft;

int n, x, a[M], m;

int main() {
	//freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> x;
	rep(i, 1, n+1) {
		cin >> a[i];
		a[i] = (a[i] < x);
	}
	rep(i, 1, n+1) if (a[i] == 1) {
		r[m].re = 1;
		rep(j, i+1, n+1) if (a[j] == 0) r[m].re++;else break; 
		l[m].re = 1; 
		per(j, 1, i) if (a[j] == 0) l[m].re++;else break;
		m++;
	}
	ll ans = 0;
	rep(i, 0, m) ans += 1ll * (ll(l[i].re+0.1) - 1) * (ll(l[i].re+0.1)) / 2;
	ans += 1ll * (ll(r[m-1].re+0.1) - 1) * (ll(r[m-1].re+0.1)) / 2;
	if (m == 0) ans = 1ll * n * (n + 1) / 2;
	reverse(l, l + m);
	fft.doit(r, l, m, m);
	cout << ans << " ";
	rep(i, 1, n+1) cout << ll(r[i + m - 2].re + 0.1) << " ";
	return 0;
}


