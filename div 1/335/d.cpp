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

const int N = 1e5 + 7;
struct node{
	int a, b, c, d, i;
} a[N];

vi ans, q;
int n, _a, _b, _c, _d, fa[N], b[N], pos, p;
pii tmp;
bool cmp(const node &a, const node &b) { return a.a < b.a;}

struct Seg{
#define ls (now << 1)
#define rs (ls | 1)
	pii tr[N * 4];
	void build(int l, int r, int now){
		if (l == r) {
			tr[now] = {a[l].b, l};
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		tr[now] = min(tr[ls], tr[rs]);
	}

	void change(int l, int r, int now, int p){
		if (l == r) {
			tr[now] = {pw(30), l};
			return;
		}
		int mid = l + r >> 1;
		if (p <= mid) change(l, mid, ls, p);
		else change(mid + 1, r, rs, p);
		tr[now] = min(tr[ls], tr[rs]);
	}
	
	void qry(int L, int R, int l, int r, int now){
		if (L <= l && R >= r) {
			tmp = min(tmp, tr[now]);
			return;
		}
		int mid = l + r >> 1;
		if (L <= mid) qry(L, R, l, mid, ls);
		if (R > mid) qry(L, R, mid + 1, r, rs);	
	}
} seg;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> _a >> _b >> _c >> _d;
		a[i] = {_a, _b, _c, _d, i};
	}
	sort(a+1, a+n+1, cmp);
	rep(i, 1, n+1) b[i] = a[i].a;
	seg.build(1, n, 1);
	memset(fa, -1, sizeof(fa));
	q.pb(0);
	rep(i, 0, sz(q)) {
		pos = upper_bound(b+1, b+n+1, a[q[i]].c) - b;
		pos--;
		if (pos >= 1) {
			while (1) {
				tmp = {pw(30), 0};
				seg.qry(1, pos, 1, n, 1);
				if (tmp.fi > a[q[i]].d) break;
				q.pb(tmp.se);
				fa[a[tmp.se].i] = a[q[i]].i;
				seg.change(1, n, 1, tmp.se);
			}
		}
	}
	if (fa[n] == -1) cout << -1;
	else {
		p = n;
		while (p) {
			ans.pb(p);
			p = fa[p];
		}
		cout << sz(ans) << endl;
		per(i, 0, sz(ans)) cout << ans[i] << " ";
	}
	return 0;
}


