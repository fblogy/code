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
const int P = 11 * 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 4e3 +7;
int f[N][N], n, k, t[N], d[N], ans;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n+1) cin >> t[i] >> d[i];
	ans = 0;
	rep(i, 1, n+1) {
		ans = max(ans, max(0, t[i] - f[i-1][k] - 1));
		f[i][0] = max(f[i-1][0] + 1, t[i]) + d[i] - 1;
		rep(j, 1, k+1) f[i][j] = min(f[i-1][j-1], max(f[i-1][j] + 1, t[i]) + d[i] - 1); 
	}
	ans = max(ans, max(0, 86400 - f[n][k]));
	cout << ans;
	return 0;
}

