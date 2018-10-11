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

const int N = 205;
int a, b, c, w, n, m, p1, p2;
char ans[N][N];
bool vis[200];

bool solve(int n, int m) {
	if (n * m % 2 == 1) return 0;
	if (n % 2 == 1) {
		if (m / 2 > a) return 0;
		a -= m / 2;
		for (int i = 1; i <= m; i += 2) ans[n][i] = ans[n][i+1] = (i / 2 % 2 == 0 ? 'a' : 'b');
		n--;
	}
	if (m % 2 == 1) {
		if (n / 2 > b) return 0;
		b -= n / 2;
		for (int i = 1; i <= n; i += 2) ans[i][m] = ans[i+1][m] = (i / 2 % 2 == 0 ? 'a' : 'b');
		m--;
	}
	if (a & 1) a--;
	if (b & 1) b--;
	if (n * m > a * 2 + b * 2 + c * 4) return 0;
	for (int i = 1; i <= n; i += 2)
		for (int j = 1; j <= m; j += 2) {
			rep(k, 'a', 'z'+1) vis[k] = 0;
			vis[ans[i-1][j]] = 1;
			vis[ans[i-1][j+1]] = 1;
			vis[ans[i][j-1]] = 1;
			vis[ans[i+1][j-1]] = 1;
			rep(k, 'c', 'z'+1) if (!vis[k]) {p1 = k;vis[p1] = 1;break;}
			rep(k, 'c', 'z'+1) if (!vis[k]) {p2 = k;vis[p2] = 1;break;}
			if (a > 0) {
				a -= 2;
				ans[i][j] = ans[i][j+1] = p1;
				ans[i+1][j] = ans[i+1][j+1] = p2; 
			}else if (b > 0){
				b -= 2;
				ans[i][j] = ans[i+1][j] = p1;
				ans[i][j+1] = ans[i+1][j+1] = p2; 
			}else {
				c --;
				ans[i][j] = ans[i][j+1] = ans[i+1][j] = ans[i+1][j+1] = p1; 
			}
		}	
	return 1;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> a >> b >> c;
	bool ok = solve(n, m);
	if (!ok) cout << "IMPOSSIBLE" << endl;
	else {
		rep(i, 1, n+1){
			rep(j, 1, m+1) cout << ans[i][j];
			cout << endl;
		}
	}
	return 0;
}


