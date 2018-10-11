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

const int N = 10;
int xx, yy, n, m, a[N][N], b[N][N], cnt, ans, s[N];

pii d[][5] = {
	{{0, 0}, {-1, 0}, {-2, 0}, {-2, -1}, {-2, 1}},
	{{0, 0}, {0, -1}, {0, -2}, {-1, -2}, {1, -2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}, {2, 1}}
};

bool check(int x, int y, int i) {
	rep(j, 0, 5) {
		xx = x + d[i][j].fi; yy = y + d[i][j].se;
		if (xx > n || xx < 1 || yy > m || yy < 1 || a[xx][yy]) return 0;
	}
	return 1;
}

int get(int p) {
	int res = 0;
	rep(i, p, n+1) res += m - s[i];//rep(j, 1, m+1) if (a[i][j] == 0) res++;
	return res;
}

void dfs(int x, int y) {
	if (y > m) {y = 1; x++;}
	if (get(max(x - 2, 1)) / 6 + cnt <= ans ) return;
 	if (x > n) {
		if (cnt > ans) {
			ans = cnt;
			rep(i, 1, n+1) rep(j, 1, m+1) b[i][j] = a[i][j];
		}
		return;
	}
	dfs(x, y+1);
	rep(i, 0, 4) if (check(x, y, i)) {
		cnt++;
		rep(j, 0, 5) {
			xx = x + d[i][j].fi; yy = y + d[i][j].se;
			a[xx][yy] = cnt;s[xx]++; 
		}
		dfs(x, y+1);
		cnt--;
		rep(j, 0, 5) {
			xx = x + d[i][j].fi; yy = y + d[i][j].se;
			a[xx][yy] = 0;s[xx]--;
		}
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	dfs(1, 1);
	cout << ans << endl;
	rep(i, 1, n+1) {
		rep(j, 1, m+1) if (b[i][j] == 0) cout << char('.');else cout << char('A' + b[i][j] - 1);
		cout << endl;
	}
	return 0;
}


