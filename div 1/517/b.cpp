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
const int inf = pw(30);
const int N = 2005;
vi ans;
string s[N];
bool f[N][N];
int v[N][N], k, n, mi, j;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n+1) cin >> s[i], s[i] = " " + s[i];
	rep(i, 0, n+1) rep(j, 0, n+1) v[i][j] = inf;
	v[0][1] = v[1][0] = 0;f[0][1] = f[1][0] = 1;
	
	rep(l, 2, 2 * n + 1) {
		mi = 1000;
		rep(i, 1, min(l, n+1)) {
			j = l - i;
			if (j > n) continue;
			v[i][j] = min(v[i-1][j], v[i][j-1]);
			if (v[i][j] + 1 <= k) mi = 'a';
			else {	
				if (f[i-1][j] || f[i][j-1]) mi = min(mi, (int)s[i][j]);
			}
		}
		ans.pb(mi);
		rep(i, 1, min(l, n+1)) {
			j = l - i;
			if (j > n) continue;
			if (f[i-1][j] || f[i][j-1]) {
				if (mi == s[i][j]) f[i][j] = 1;
				else {
					if (v[i][j] + 1 <= k) v[i][j]++, f[i][j] = 1;
					else v[i][j] = inf;
				}
			}else v[i][j] = inf;
		}
	}
	rep(i, 0, sz(ans)) cout << char(ans[i]);
	return 0;
}


