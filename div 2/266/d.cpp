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

const int N = 1e5 + 7;
int n, a[N], h, ans, cnt;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> h;
	rep(i, 1, n+1) cin >> a[i], a[i] = h - a[i];
	per(i, 1, n+2) a[i] = a[i] - a[i-1];
	n++;
	ans = 1;
	rep(i, 1, n+1) {
		if (a[i] == 1) cnt++;
		else if (a[i] == 0) ans = mul(ans, cnt + 1);
		else if (a[i] == -1) {
			ans = mul(ans, cnt), cnt--;
			if (cnt < 0) {cout << 0;return 0;}
		}
		else {
			cout << 0;
			return 0;
		}
	}
	if (cnt != 0) cout << 0;
	else cout << ans;
	return 0;
}


