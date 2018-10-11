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

const int N = 2e3 + 7;
ll w1[N], w2[N], x, a[N], b[N];
int n, m, ans, len;
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i], a[i] += a[i-1];
	rep(i, 1, m+1) cin >> b[i], b[i] += b[i-1];
	cin >> x;
	rep(i, 1, n+1) w1[i] = pw(30);
	rep(i, 1, m+1) w2[i] = pw(30);
	rep(i, 1, n+1)
		rep(j, i, n+1) {
			len = j - i + 1;
			w1[len] = min(w1[len], a[j] - a[i-1]);
		}
	rep(i, 1, m+1)
		rep(j, i, m+1) {
			len = j - i + 1;
			w2[len] = min(w2[len], b[j] - b[i-1]);
		}
	rep(i, 1, n+1) rep(j, 1, m+1) if (w1[i] * w2[j] <= x) ans = max(ans, i * j);
	cout << ans;
	return 0;
}


