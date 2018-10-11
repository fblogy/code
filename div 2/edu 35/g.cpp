#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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
const int M = 60;
int ls[N * M], rs[N * M], tid, n, ans[N], a[N], root[N], q, L, R, x, y;

int build(int l, int r, int now, int p) {
	if (now == 0) now = ++tid;
	if (l == r) return now;
	int mid = (l + r) >> 1;
	if (p <= mid) ls[now] = build(l, mid, ls[now], p);
	else rs[now] = build(mid+1, r, rs[now], p);
	return now;	
}

void merge(int &x, int &y) {
	if (!y) return;
	if (!x) {
		x = y;y = 0;
		return;
	}
	merge(ls[x], ls[y]);
	merge(rs[x], rs[y]);
	y = 0;
}

void change(int L, int R, int l, int r, int &x, int &y) {
	int mid = (l + r) >> 1;
	if (x == y) return;
	if (!x) x = ++tid;
	if (L <= l && R >= r) {
		merge(x, y);
		return;
	}
	if (L <= mid) change(L, R, l, mid, ls[x], ls[y]);
	if (R > mid) change(L, R, mid+1, r, rs[x], rs[y]);
}

void qry(int l, int r, int now, int x) {
	int mid = l + r >> 1;
	if (!now) return;
	if (l == r) {
		ans[l] = x;
		return;
	}
	qry(l, mid, ls[now], x);
	qry(mid+1, r, rs[now], x);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n; 
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) root[a[i]] = build(1, n, root[a[i]], i);
	cin >> q;
	rep(i, 0, q) {
		cin >> L >> R >> y >> x;
		change(L, R, 1, n, root[x], root[y]);
	}
	rep(i, 1, 100+1) qry(1, n, root[i], i);
	rep(i, 1, n+1) cout << ans[i] << " ";
	return 0;
}


