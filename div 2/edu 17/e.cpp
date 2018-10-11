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
const int M = 60;

int tid, n, k, root[N], x, y, z, L, R, p;
ll ans;
vi X;
struct node{
	int x, r, f;
} a[N];

bool cmp(node a, node b) {return a.r > b.r;}

struct Seg{
	int tr[N * M], ls[N * M], rs[N * M];
	void change(int l, int r, int &now, int p) {
		if (!now) now = ++tid;
		if (l == r) {
			tr[now]++;
			return;
		}
		int mid = l + r >> 1;
		if (p <= mid) change(l, mid, ls[now], p);
		else change(mid+1, r, rs[now], p);
		tr[now] = tr[ls[now]] + tr[rs[now]];
	}
	
	void qry(int L, int R, int l, int r, int now) {
		if (!now) return;
		if (L <= l && R >= r) {
			ans += tr[now];
			return;
		}
		int mid = l + r >> 1;
		if (L <= mid) qry(L, R, l, mid, ls[now]);
		if (R > mid) qry(L, R, mid+1, r, rs[now]);
	}
} seg;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n+1) {
		cin >> x >> y >> z;
		a[i] = {x, y, z};
		X.pb(x);
	}
	sort(a+1, a+n+1, cmp);
	sort(all(X));
	X.erase(unique(all(X)), X.end());
	rep(i, 1, n+1) {
		L = lower_bound(all(X), a[i].x - a[i].r) - X.begin(); L++;
		R = upper_bound(all(X), a[i].x + a[i].r) - X.begin();
		if (L <= R) rep(j, max(1, a[i].f - k), a[i].f + k + 1) seg.qry(L, R, 1, n, root[j]);
		p = lower_bound(all(X), a[i].x) - X.begin(); p++;
		seg.change(1, n, root[a[i].f], p);
	}
	cout << ans;
	return 0;
}


