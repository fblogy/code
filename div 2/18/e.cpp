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

const int N = 505;
string s[N];
int p, n, m, x, y;
int f[N][30][30], cnt[N][30][2], w[N][2];
pii g[N][30][30];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) rep(j, 0, m) cnt[i][s[i][j] - 'a'][j & 1]++, w[i][j & 1]++;
	memset(f, 1, sizeof(f));
	rep(i, 0, 26) rep(j, 0, 26) {
		if (i != j) f[0][i][j] = w[0][0] - cnt[0][i][0] + w[0][1] - cnt[0][j][1]; 
	} 
	rep(i, 1, n){
		rep(j, 0, 26)
			rep(k, 0, 26) if (k != j) 
				rep(l, 0, 26) if (l != j)
					rep(m, 0, 26) if (m != l && m != k){
						int tmp = w[i][0] - cnt[i][l][0] +  w[i][1] - cnt[i][m][1];
						if (f[i-1][j][k] + tmp < f[i][l][m]) {
							f[i][l][m] = f[i-1][j][k] + tmp;
							g[i][l][m] = {j, k};
						}
					}
	}
	int ans = pw(30);
	rep(i, 0, 26) rep(j, 0, 26) if (f[n-1][i][j] < ans) {
		ans  = f[n-1][i][j];
		x = i; y = j;
	}
	p = n - 1;
	cout << ans << endl;
	while (p >= 0) {
		rep(i, 0, m) if (!(i & 1)) s[p][i] = x + 'a';else s[p][i] = y + 'a';//cout << char(x + 'a');else cout << char(y + 'a');
		pii & tmp = g[p][x][y];
		x = tmp.fi; y = tmp.se;
		p--;
	}
	rep(i, 0, n) cout << s[i] << endl; 
	return 0;
}


