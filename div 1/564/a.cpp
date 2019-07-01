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
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 200;
int n, m, a[N], f[N][N][N], s1, s2, s, w[N], tmp[N], ans[N];

int inv(int x) {return kpow(x, P - 2);}
 
int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> a[i];
	} 
	rep(i, 1, n+1) {
		cin >> w[i], s += w[i];
		if (a[i]) s2 += w[i];else s1 += w[i];
	}
	f[0][s][s2] = 1;
	int d = m;
	rep(i, 1, m+1) {
		rep(j, 1, s + m + 1) 
			rep(k, 1, j+1){
				int &t = f[i][j+1][k+1];
				t = add(t, mul(f[i-1][j][k], mul(k, inv(j))));
				int &t2 = f[i][j-1][k];
				t2 = add(t2, mul(f[i-1][j][k], mul(j - k, inv(j))));
			}
	}
	rep(i, 1, s + m + 1)
		rep(j, s2, i+1) {
			rep(l, 1, n+1) if (a[l]) {
				memset(tmp, 0, sizeof(tmp));
				tmp[0] = 1;
				rep(k, 1, j - s2 + 1)  {
					per(o, 0, k+1) {
						int z = 0;
						z = add(z, mul(tmp[o], mul(s2 + k - 1 - (w[l] + o), inv(s2 + k - 1))));
						if (o) z = add(z, mul(tmp[o-1], mul(w[l] + o -1, inv(s2 + k - 1))));
						tmp[o] = z;	
					}
				}
				rep(k, 0, j+1) ans[l] = add(ans[l], mul(tmp[k], mul(w[l] + k, f[m][i][j]))); 		
			}else {
				memset(tmp, 0, sizeof(tmp));
				tmp[w[l]] = 1;
				rep(k, 1, s1 - (i - j) + 1)  {
					rep(o, 0, w[l]+1) {
						int z = 0;
						z = add(z, mul(tmp[o], mul(s1 - (k - 1) - o, inv(s1 - (k - 1)))));
						z = add(z, mul(tmp[o + 1], mul(o + 1, inv(s1 - (k - 1)))));
						tmp[o] = z;	
					}
				}
				rep(k, 0, w[l] + 1) ans[l] = add(ans[l], mul(tmp[k], mul(k, f[m][i][j]))); 
			}
		}
	rep(i, 1, n+1) cout << ans[i] << endl; 
	return 0;
}


