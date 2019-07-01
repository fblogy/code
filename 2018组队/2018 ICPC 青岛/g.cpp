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
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 105;
int a[N], T, n, m, d, ans, f[N][2][N * N / 2], s[N][N], po[N * N];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		rep(i, 1, n+1) cin >> a[i];
		rep(i, 1, n * (n + 1) / 2 + 1) po[i] = kpow(i, m);
		rep(i, 1, n+1) {
			int res = 0, t = 0;
			rep(j, i, n+1) if (a[j] == 1){
				res += t * (t + 1) / 2;t = 0;
				s[i][j] = res;
			}else {
				t++; s[i][j] = res + t * (t + 1) / 2;
			}
		}
		rep(i, 1, n+1) if (a[i] == 2){
			rep(j, 1, i) if (a[j] == 2){
				d = s[j+1][i-1];
				rep(k, 0, j * (j + 1) / 2 + 1) {
					if (f[j][1][k]) (f[i][0][k + d] += f[j][1][k]) %= P;
					if (f[j][0][k]) (f[i][1][k + d] += f[j][0][k]) %= P;
				}
			}
			d = s[1][i-1]; 
			f[i][0][d] ++;
		}
		ans = s[1][n];
		ans = kpow(ans, m);
		rep(i, 1, n+1) if (a[i] == 2) {
			d = s[i+1][n];
			rep(k, 0, i * (i + 1) / 2 + 1) {
				ans = add(ans, mul(f[i][1][k], po[d + k]));
				ans = sub(ans, mul(f[i][0][k], po[d + k]));
				f[i][1][k] = f[i][0][k] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


