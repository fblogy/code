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

#define lg2(n) (31-__builtin_clz(n))

const int N = 1030;
const int LGN=lg2(N)+1;
short f[N][N], a[N][N];
int n, m, q, l, r, mid, a1, b1, a2, b2, ans;

namespace ST_2D{
	const int N = 1030;
	int LOG[N], P[20], dep1, dep2;
	short st[11][11][N][N];
	void build(int n, int m, short a[][N]){
		rep(i, 0, 11) P[i] = 1<<i;
		rep(i, 2, 1025) LOG[i] = LOG[i>>1]+1;
		for(dep1 = 0; (1<<dep1) < n; dep1++);
		for(dep2 = 0; (1<<dep2) < m; dep2++);
		rep(i, 1, n+1)
			rep(j, 1, m+1)
				st[0][0][i][j] = a[i][j];//modi
		rep(i, 1, n+1)
			rep(j, 1, dep2+1)
				rep(k, P[j], m+1)
					st[0][j][i][k] = max(st[0][j-1][i][k], st[0][j-1][i][k-P[j-1]]);
		rep(i, 1, dep1+1)
			rep(j, P[i], n+1)
				rep(k, 0, dep2+1) //attention to range of k
					rep(l, P[k], m+1)
						st[i][k][j][l]=max(st[i-1][k][j-P[i-1]][l], st[i-1][k][j][l]);
	}
	int qry(int x1, int y1, int x2, int y2){
		int l1 = LOG[x2-x1+1], l2 = LOG[y2-y1+1];
		int res1 = max(st[l1][l2][x1+P[l1]-1][y1+P[l2]-1], st[l1][l2][x2][y2]);
		int res2 = max(st[l1][l2][x1+P[l1]-1][y2], st[l1][l2][x2][y1+P[l2]-1]);
		return max(res1, res2);
	}
}
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) rep(j, 1, m+1) cin >> a[i][j];
	rep(i, 1, n+1) rep(j, 1, m+1) 
		if (a[i][j] == 0) f[i][j] = 0;
		else f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1])+1; 
	ST_2D :: build(n, m, f);
	cin >> q;
	rep(i, 1, q+1) {
		cin >> a1 >> b1 >> a2 >> b2;
		l = 0; r = min(a2 - a1 + 1, b2 - b1 + 1);
		ans = 0;
		while (l <= r) {
			mid = l + r >> 1;
			if (ST_2D :: qry(a1+mid-1, b1+mid-1, a2, b2) >= mid) {
				ans = max(ans, mid);
				l = mid + 1;
			}else r = mid - 1;
		} 
		cout << ans << endl;
		
	} 
	return 0;
}

