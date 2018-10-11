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
const int N = 2e5 + 7;
ll l[N], r[N], s[N], t[N], w, p, ans, n, h;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> h;
	rep(i, 1, n+1) cin >> l[i] >> r[i], s[i] = s[i-1] + r[i] - l[i];
	rep(i, 1, n) t[i+1] = l[i+1] - r[i];
	p = 2;
	ans = h;
	w = 0;
	rep(i, 1, n+1) {
		w -= t[i];
		while (p <= n && w + t[p] < h) {w += t[p]; p++;}
		ans = max(ans, h + s[p - 1] - s[i-1]);
	}
	cout << ans;
	return 0;
}

