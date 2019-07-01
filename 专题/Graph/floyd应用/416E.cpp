// 求任意两点间可能在最短路上边数量 
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
int n, m, u, v, w, a[N][N], f[N][N], cnt[N][N], c[N][N];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	rep(i, 1, n+1) f[i][i] = 0;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = f[u][v] = f[v][u] = w;
	}  
	rep(k, 1, n+1)
		rep(i, 1, n+1)
			rep(j, 1, n+1) 
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	rep(i, 1, n+1) {
		rep(j, 1, n+1) 
			rep(k, j+1, n+1) if (a[j][k]) {
				if (f[i][k] == f[i][j] + a[j][k]) cnt[i][k]++;
				else if (f[i][j] == f[i][k] + a[j][k]) cnt[i][j]++;
			}
		rep(j, 1, n+1) rep(k, 1, n+1) if (f[i][j] == f[i][k] + f[k][j]) c[i][j] += cnt[i][k];
	}
	rep(i, 1, n+1) rep(j, i+1, n+1) cout << c[i][j] << " ";
	return 0;
}


