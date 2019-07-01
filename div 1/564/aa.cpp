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
int n, m, a[N], f[N][N], s1, s2, s, w[N], tmp[N], ans[N], in[5000];

int inv(int x) {if (!in[x]) return in[x] = kpow(x, P - 2);else return in[x];}
 
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
	f[0][0] = 1;
	rep(i, 1, m+1) {
		rep(j, 0, m+1) {
			int &t = f[i][j+1], sum = s + j - (i - 1 - j);
			if (i - 1 - j > s1) continue;
			t = add(t, mul(f[i-1][j], mul(j + s2, inv(sum))));
			int &t2 = f[i][j];
			t2 = add(t2, mul(f[i-1][j], mul(sum - j - s2, inv(sum))));
		}
	}
	rep(l, 1, n+1) if (a[l]) {
		memset(tmp, 0, sizeof(tmp));
		tmp[0] = 1;
		rep(k, 1, m + 1)  {
			per(o, 0, k+1) {
				int z = 0;
				z = add(z, mul(tmp[o], mul(s2 + k - 1 - (w[l] + o), inv(s2 + k - 1))));
				if (o) z = add(z, mul(tmp[o-1], mul(w[l] + o - 1, inv(s2 + k - 1))));
				tmp[o] = z;	
			}
			rep(o, 0, k+1) ans[l] = add(ans[l], mul(tmp[o], mul(w[l] + o, f[m][k]))); 	
		}
		ans[l] = add(ans[l], mul(w[l], f[m][0]));		
	}else {
		memset(tmp, 0, sizeof(tmp));
		tmp[0] = 1;
		rep(k, 1, min(m, s1) + 1)  {
			per(o, 0, min(w[l], k) + 1) {
				int z = 0;
				z = add(z, mul(tmp[o], mul(s1 - (k - 1) - (w[l] - o), inv(s1 - (k - 1)))));
				if (o) z = add(z, mul(tmp[o-1], mul(w[l] - (o - 1), inv(s1 - (k - 1)))));
				tmp[o] = z;	
			}
			rep(o, 0, k+1) ans[l] = add(ans[l], mul(tmp[o], mul(w[l] - o, f[m][m - k]))); 
		}		
		ans[l] = add(ans[l], mul(w[l], f[m][m]));
	}
	rep(i, 1, n+1) cout << ans[i] << endl; 
	return 0;
}


