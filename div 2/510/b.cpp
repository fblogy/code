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

const int N = 1e3 + 6;
int f[10], a[N], b[N], n;
string s;
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i] >> s;
		rep(j, 0, sz(s)) {
			if (s[j] == 'A') b[i] |= 1;
			if (s[j] == 'B') b[i] |= 2;
			if (s[j] == 'C') b[i] |= 4;
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	rep(i, 1, n+1) {
		rep(j, 0, 8) f[j|b[i]] = min(f[j|b[i]], f[j] + a[i]);
	}
	if (f[7] > 10000000) cout << -1;else cout << f[7];
	return 0;
}


