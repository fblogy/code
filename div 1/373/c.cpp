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
//----
const int N = 2;
const int M = 1e5 + 7;

struct Mat {
    int r[N][N];
    Mat() {memset(r,0,sizeof(r));}
    Mat operator * (Mat b) {
        Mat c;
        rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) c.r[i][j] = add(c.r[i][j], mul(r[i][k], b.r[k][j]));
        return c;
    }
    
    Mat operator + (Mat b) {
		Mat c;
		rep(i, 0, N) rep(j, 0, N) c.r[i][j] = add(r[i][j], b.r[i][j]);
		return c;
	}
};

Mat kpow(Mat a,ll k) {
    Mat b;
    rep(i, 0, N) b.r[i][i]=1;
    for(;k;k>>=1,a=a*a) if(k&1) b=b*a;
    return b;
}

int n, m, a[M], op, l, r, x;
Mat E, w0, w, ans;

struct Seg{
#define ls (now << 1)
#define rs (ls | 1)
	static const int N = M << 2;
	Mat tr[N], tip[N];
	
	void build(int l, int r, int now) {
		tip[now] = E;
		if (l == r) {
			tr[now] = kpow(w0, a[l]);
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		tr[now] = tr[ls] + tr[rs];
	}

	void down(int now) {
		tip[ls] = tip[ls] * tip[now];
		tip[rs] = tip[rs] * tip[now];
		tr[now] = (tr[ls] * tip[ls]) + (tr[rs] * tip[rs]);
		tip[now] = E;
	}

	void change(int L, int R, int l, int r, int now) {
		if (l != r) down(now);
		if (L <= l && R >= r) {
			tip[now] = tip[now] * w;
			return;
		}
		int mid = l + r >> 1;
		if (L <= mid) change(L, R, l, mid, ls);
		if (R > mid) change(L, R, mid+1, r, rs);
		tr[now] = (tr[ls] * tip[ls]) + (tr[rs] * tip[rs]);
	}

	void qry(int L, int R, int l, int r, int now) {
		if (l != r) down(now);
		if (L <= l && R >= r) {
			//tip[now] = tip[now] * w;
			ans = ans + (tr[now] * tip[now]);
			return;
		}
		int mid = l + r >> 1;
		if (L <= mid) qry(L, R, l, mid, ls);
		if (R > mid) qry(L, R, mid+1, r, rs);
		tr[now] = (tr[ls] * tip[ls]) + (tr[rs] * tip[rs]);
	}

} seg;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 0, N) E.r[i][i] = 1;
	w0.r[0][0] = w0.r[0][1] = w0.r[1][0] = 1;
	seg.build(1, n, 1);
	rep(i, 1, m+1) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> x;
			w = kpow(w0, x);
			//rep(i, 0, 2) rep(j, 0, 2) de(w.r[i][j]);
			seg.change(l, r, 1, n, 1);
		}else {
			ans = Mat();
			seg.qry(l, r, 1, n, 1);
			cout << ans.r[0][1] << endl;
		}
	}
	return 0; 
}


