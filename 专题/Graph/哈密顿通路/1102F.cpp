// ×´Ñ¹dpÇó¹şÃÜ¶ÙÍ¨Â· 
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

const int N = 1e4 + 6;
int g[20][20], a[20][N], n, m, S, f[17][1 << 16], l, r, mid, ans;

bool check(int mid) {
	rep(i, 1, n+1) rep(j, i+1, n+1) {
		g[i][j] = 1;
		rep(k, 1, m+1) g[i][j] = g[i][j] & (abs(a[i][k] - a[j][k]) >= mid);
		g[j][i] = g[i][j];
	}	
	rep(s, 1, n+1) {
		memset(f, 0, sizeof(f));
		f[s][pw(s-1)] = 1;
		S = pw(n);
		rep(mask, 0, S) {
			rep(i, 1, n+1) if (f[i][mask]) {
				rep(j, 1, n+1) if (g[i][j] && !(pw(j-1) & mask)) f[j][mask | pw(j-1)] = 1;
			}
		}
		rep(i, 1, n+1) if (f[i][S-1]) {
			bool ok = 1;
			rep(j, 1, m) ok &= (abs(a[i][j] - a[s][j+1]) >= mid);
			if (ok) return 1; 
		}
	}
	return 0;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m; 
	rep(i, 1, n+1) rep(j, 1, m+1) cin >> a[i][j];
	l = 0; r = 1e9;
	while (l <= r) {
		mid = l + r >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
	return 0;
}


