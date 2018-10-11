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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e6 + 7;
bool isp[N], ok[N];
int ans, x;
vi D[N];

void prime(int n) {
	memset(isp, 1, sizeof(isp));
	isp[1] = 0;
	rep(i, 2, n+1) {
		for(int j = i + i; j <= n; j += i) {
			isp[j] = 0;
			if (isp[i]) D[j].pb(i);
		}
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> x;
	prime(x);
	for (auto d : D[x]) {
		rep(i, x - d + 1, x + 1) ok[i] = 1;
	}
	ans = 1 << 30;
	rep(i, 1, x+1) if (ok[i]) {
		for (auto d : D[i]) {
			ans = min(ans, i - d + 1);
		}
	}
	cout << ans;
	return 0;
}


