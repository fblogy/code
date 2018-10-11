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
int B[N], T[N], n, m, a[N], cnt;
bool vis[N], g[N][N];
string s[N];

void getB(int n) {
	B[0] = B[1] = T[0] = 1;
	rep(i, 2, n+1) {
		T[i-1] = B[i-1];
		per(j, 0, i - 1) T[j] = add(T[j], T[j + 1]);
		B[i] = T[0];
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> m >> n;
	getB(m);
	rep(i, 1, n+1) cin >> s[i];
	rep(i, 1, n+1) {
		rep(j, 0, m)
			rep(k, j+1, m) 
				if (s[i][j] != s[i][k]) g[j][k] = 1;
	}
	rep(i, 0, m) if (!vis[i]) {
		a[++cnt] = 1;vis[i] = 1;
		rep(j, i+1, m) if (g[i][j] == 0) vis[j] = 1, a[cnt]++;
	}
	int ans = 1;
	rep(i, 1, cnt+1) ans = mul(ans, B[a[i]]);
	cout << ans;
	return 0;
}


