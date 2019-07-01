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

const ll INF = pw(62);
const int N = 1000005;

int T, n, Q, D, now;

struct node{
	int d[2], l, r, mi[2], ma[2], tip, ans, p;//sum, val, minp, p, id;
	bool operator <(const node &b)const{
		return d[Q] < b.d[Q];
	}
};

//node a[N], ans, v, b[N];
node v;
/*struct KDTree{
	static const int N = 1e6 + 7;
	int root;
	node tr[N];

	inline void up(node &a, const node &b){
		rep(i, 0, D) {
			a.mi[i] = min(a.mi[i], b.mi[i]);
			a.ma[i] = max(a.ma[i], b.ma[i]);
		}
	}

	int build(int l,int r,int k, int nn, int mm) {
		if (l > r) return 0;
		int mid = l+r>>1; Q = k;
		nth_element(a+l, a+mid, a+r+1);
		tr[mid] = a[mid];
		rep(i, 0, D) tr[mid].ma[i] = tr[mid].mi[i] = tr[mid].d[i];
		if (nn > mm) {nn >>= 1;k = 0;}else {mm >>=1; k = 1;}
		tr[mid].l = build(l, mid-1, k, nn, mm);
		tr[mid].r = build(mid+1, r, k, nn, mm);
		if (tr[mid].l) up(tr[mid], tr[tr[mid].l]);
		if (tr[mid].r) up(tr[mid], tr[tr[mid].r]);
		return mid;
	}

	inline ll get(const node &v, int x) { // dis function need update 
		if (!x) return 0;
 		rep(i, 0, D) if (v.mi[i] > tr[x].ma[i] || v.ma[i] < tr[x].mi[i]) return 0;
		return 1;
	}
 
	inline void check(const node &v, const node &p, int tip) {  
		rep(i, 0, D) if (v.mi[i] > p.d[i] || p.d[i] > v.ma[i]) return;
		now = max(now, max(tip, p.p));
		return;
	}
 
	inline void check2(const node &v, node &p, int now) {  
		rep(i, 0, D) if (v.mi[i] > p.d[i] || p.d[i] > v.ma[i]) return;
		p.p = max(p.p, now);
		return;
	}
	void ask(const node &v, int x, int tip) {
		if (!x) return;
		tip = max(tip, tr[x].tip);
		int ok = 0;
		rep(i, 0, D) if (v.mi[i] <= tr[x].mi[i] && tr[x].ma[i] <= v.ma[i]) ok++;
		if (ok == 2) {
			now = max(now, max(tr[x].ans, tip));
			return;
		}
		check(v, tr[x], tip);
		bool lm = get(v, tr[x].l), rm = get(v, tr[x].r);
		if (lm) ask(v, tr[x].l, tip);
		if (rm) ask(v, tr[x].r, tip);
	}
	
	void change(const node &v, int x, int now) {
		if (!x) return;
		tr[x].ans = max(tr[x].ans, now);
		int ok = 0;
		rep(i, 0, D) if (v.mi[i] <= tr[x].mi[i] && tr[x].ma[i] <= v.ma[i]) ok++;
		if (ok == 2) {
			tr[x].tip = max(tr[x].tip, now);
			return;
		}
		check2(v, tr[x], now);
		bool lm = get(v, tr[x].l), rm = get(v, tr[x].r);
		if (lm) change(v, tr[x].l, now);
		if (rm) change(v, tr[x].r, now);
	}
} kdt;*/

int nn, mm, q, d, s, h, x, y;
int a[1005][1005];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	srand(time(0));
	//cin >> nn >> mm >> q;
	int M = 1000;
	nn = mm = M; q = 20000;
	D = 2;
	/*rep(i, 0, nn) rep(j, 0, mm) {
		a[++n].d[0] = i;
		a[n].d[1] = j;
		a[n].tip = a[n].ans = a[n].p = 0;
	}
	kdt.root = kdt.build(1, n, 0, nn / 2, mm);
	*/
	rep(i, 0, q) {
		//cin >> d >> s >> h >> x >> y;
		//d = s = h = x = y = 1;
		x = rand() % M;
		y = rand() % M;
		d = rand() % (M - x);
		s = rand() % (M - y);
		assert(x + d < M && y + s < M);
		h = rand() % 100000; 
		v.mi[0] = x;
		v.ma[0] = x + d -1;
		v.mi[1] = y;
		v.ma[1] = y + s -1;
		now = 0;
		rep(i, x, x + d) rep(j, y, y+d) now = max(a[i][j], now);
		now += h;
		rep(i, x, x + d) rep(j, y, y+d) now = max(a[i][j], now);
		//kdt.ask(v, kdt.root, 0);
		//now += h;
		//kdt.change(v, kdt.root, now);
	}
	//int ans = 0;
	//rep(i, 1, n+1) ans = max(ans, kdt.tr[i].ans), ans = max(ans, kdt.tr[i].tip), ans = max(ans, kdt.tr[i].p);
	//cout << ans;
	return 0;
}


