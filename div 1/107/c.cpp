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

const int N = 150005;
struct node{
	db l, r, sum, ans;
} tr[N * 4], ans;

int n, q, L, R;
db a[N], c, p, S;

#define ls (now << 1)
#define rs (ls | 1)

node merge(node a, node b) {
	node c;
	c.l = max(a.l, a.sum + b.l);
	c.r = max(b.r, b.sum + a.r);
	c.ans = max(a.ans, b.ans);
	c.ans = max(c.ans, max(c.l, c.r));
	c.ans = max(c.ans, a.r + b.l);
	c.sum = a.sum + b.sum;
	return c;
}

void build(int l, int r, int now) {
	if (l == r) {
		tr[now].ans = tr[now].r = tr[now].l = max(0.0, a[l]);
		tr[now].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	tr[now] = merge(tr[ls], tr[rs]);
}

void qry(int L, int R, int l, int r, int now) {
	if (L <= l && R >= r) {
		if (ans.ans == -1) ans = tr[now];
		else ans = merge(ans, tr[now]);
		return;
	}
	int mid = l + r >> 1;
	if (L <= mid) qry(L, R, l, mid, ls);
	if (R > mid) qry(L, R, mid+1, r, rs);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	cin >> n >> q >> c;
	rep(i, 1, n+1) cin >> a[i];
	n--;
	rep(i, 1, n+1) cin >> p, a[i] = (a[i+1] - a[i]) / 2 - c * p / 100;
	build(1, n, 1);
	rep(i, 0, q) {
		cin >> L >> R;R--;
		ans.ans = -1;
		qry(L, R, 1, n, 1);
		S += ans.ans;
	}
	cout << S << endl;
	return 0;
}


