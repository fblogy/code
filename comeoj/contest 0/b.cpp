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
#define lb(x) ((x) & -(x))
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

int T, n, m, k, q, p, inv, r;
int f[505][505][505], t, w[505], ans;
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m >> k >> p >> q;
		inv = kpow(100, P - 2);
		r = mul(100 - p - q, inv);
		p = mul(p, inv);
		q = mul(q, inv);
		rep(i, 0, m) rep(j, 1, n+1) rep(l, 0, n) f[i][j][l] = 0;
		//memset(f, 0, sizeof(f));
		//de((p == q));
		f[0][1][0] = 1;
		rep(i, 0, m-1) {
			rep(j, 1, n+1) {
				rep(l, 0, j) if (f[i][j][l]){
					int c1 = mul(f[i][j][l], r), c2 = mul(f[i][j][l], p), c3 = mul(f[i][j][l], q);
					f[i+1][j][l] = add(f[i+1][j][l], c1);
					t = l - 1;
					if (t < 0) f[i+1][min(j+1, n)][0] = add(f[i+1][min(j+1, n)][0], c2);
					else f[i+1][j][t] = add(f[i+1][j][t], c2);
					t = l + 1;
					if (t > j-1) f[i+1][min(j+1, n)][min(t, n-1)] = add(f[i+1][min(j+1, n)][min(t, n-1)], c3);
					else f[i+1][j][t] = add(f[i+1][j][t], c3);
				} 
			}
		}
		ans = 0;
		rep(i, 1, n+1) {
			w[i] = 0;
			rep(j, 0, i) w[i] = add(w[i], f[m-1][i][j]);
		}
		//rep(l, 0, m) rep(j, 0, n) w[n] = add(w[n], f[l][n][j]);
		rep(i, 1, n+1) ans = add(ans, mul(kpow(i, k), w[i]));
		ans = mul(ans, kpow(100, m-1));
		cout << ans << endl;
	}
	return 0;
}


