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

int a[10][5], n, m, k, s, ans, x, y;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k >> s;
	rep(i, 1, k+1) rep(j, 0, 4) a[i][j] = -pw(30);
	rep(i, 1, n+1) rep(j, 1, m+1) {
		cin >> x; 
		rep(l, 0, 4) {
			int tmp = 0;
			if (pw(0) & l) tmp += i;else tmp -= i;
			if (pw(1) & l) tmp += j;else tmp -= j;
			a[x][l] = max(a[x][l], tmp);
		}
	}
	cin >> y;
	ans = -pw(30);
	rep(i, 1, s) {
		cin >> x;
		rep(j, 0, 4) ans = max(ans, a[x][j] + a[y][j^3]);
		y = x;
	}
	cout << ans;
	return 0;
}


