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

const int N = 2e5 + 6;
const int NN = 1e6 + 7;
struct node {
	int l, r, i;
} q[N];
int n, Q, ans[N], M, p[N], x, a[N], now, s[N];
int val[NN], inv[NN], f[NN], g[NN], pos[NN];
template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n;T a1[N],a2[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,1);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p] = mul(a[p], d); }
	T sum(T *a,int p) { T r=1; for(; p>=1; p-=p & -p) r = mul(r, a[p]); return r;}
	T qry(int l, int r) { return mul(sum(a1, r), kpow(sum(a1, l - 1), P - 2));}
};

Fenwick<int> fen;

void prime(int n) {
	rep(i, 2, n+1) {
		if (!f[i]) {
			p[++M]=i;
			f[i] = g[i] = i;
		}
		for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= n; j++){
			f[k = i * p[j]] = p[j];
			if (p[j] < f[i]) g[k] = p[j];		
			else g[k] = g[i] * p[j];
		}
	}
	inv[1] = 1;
	rep(i, 2, n+1) inv[i] = mul(P - P / i, inv[P % i]);
	rep(i, 1, n+1) val[i] = mul(i - 1, inv[i]);
}

void change(int p) {
	x = a[p];
	while (x > 1) {
		if (pos[f[x]]) fen.add(fen.a1, pos[f[x]], kpow(val[f[x]], P - 2));
		pos[f[x]] = p; fen.add(fen.a1, pos[f[x]], val[f[x]]);
		x /= g[x];
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	prime(1e6);
	cin >> n;
	s[0] = 1;
	fen.ini(n);
	rep(i, 1, n+1) cin >> a[i], s[i] = mul(s[i-1], a[i]);
	cin >> Q;
	rep(i, 0, Q) cin >> q[i].l >> q[i].r, q[i].i = i;
	sort(q, q + Q, [&] (node a, node b) {return a.r < b.r;});
	now = 0;
	rep(i, 0, Q) {
		while (now < q[i].r) change(++now);
		ans[q[i].i] = mul(mul(s[q[i].r], kpow(s[q[i].l-1], P - 2)), fen.qry(q[i].l, q[i].r));
	} 
	rep(i, 0, Q) cout << ans[i] << endl;
	return 0;
}


