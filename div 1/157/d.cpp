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

const int N = 1e3 + 7;
db p[N][N], w[N], s[N], tmp1, ans, tmp2;
int n, m, x, y, a[N];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) rep(j, i+1, n+1) if (a[i] > a[j]) p[i][j] = 1;else p[j][i] = 1;
	rep(t, 1, m+1) {
		cin >> x >> y;
		rep(i, 1, n+1) {
			if (i == x || i == y) continue;
			tmp1 = p[x][i] + p[y][i];
			tmp2 = p[i][x] + p[i][y];
			p[x][i] = p[y][i] = tmp1 / 2;
			p[i][x] = p[i][y] = tmp2 / 2;
		}
		p[x][y] = p[y][x] = 0.5;
	}
	rep(i, 1, n+1) rep(j, i+1, n+1) ans += p[i][j];
	cout << ans;
	return 0;
}


