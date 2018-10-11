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

const int N = 2e5 + 7;
int n, m;
ll a[N], s[N], t, ans, x, p;
vector<ll> V;

template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n;T a1[N],a2[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,0);fill_n(a2+1,n=_n,0);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p]+=d; }
	void add(int l,int r,T d) {
		add(a1, l, d), add(a1, r + 1, -d);
		add(a2, l, d * (l - 1)), add(a2, r + 1, -d * r);
	} 
	T sum(T *a,int p) { T r=0; for(; p>=1; p-=p & -p) r+=a[p]; return r; }
	T pre(int p) { return !p ? 0 : sum(a1, p) * p - sum(a2, p);}
	T qry(int l,int r) {return pre(r)-pre(l-1); }
};
Fenwick<ll> fen;
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> t;
	rep(i, 1, n+1) cin >> a[i], s[i] = s[i-1] + a[i], V.pb(s[i]);
	V.pb(0);
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	m = sz(V);
	//rep(i, 0, m) cout << V[i] << endl;
	fen.ini(m);
	p = lower_bound(all(V), 0) - V.begin();
	p++;
	fen.add(p, p, 1);
	rep(i, 1, n+1) {
		x = s[i] - t;
		//de(x);
		p = upper_bound(all(V), x) - V.begin();
		p++;
		//de(p);
		if (p <= m) ans += fen.qry(p, m);
		//de(ans);
		p = lower_bound(all(V), s[i]) - V.begin();
		p++;
		fen.add(p, p, 1);
	}
	cout << ans;
	return 0;
}


