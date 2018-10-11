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
int n, ans[N], pos, p, num, vis[N], m, d, r[N], l[N];
pii a[N];
int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> d;
	rep(i, 1, n+1) cin >> a[i].fi, a[i].se = i;
	sort(a + 1, a + n + 1);
	p = 1;
	rep(i, 1, n+1) {
		if(!vis[i]) {num++;ans[a[i].se] = num;}
		p++;
		while (p <= n && a[p].fi <= a[i].fi + d) p++;
		if(p <= n) {
			vis[p] = 1;
			ans[a[p].se] = ans[a[i].se];
		}
	}
	cout << num << endl;
	rep(i, 1, n+1) cout << ans[i] << " ";
	return 0;
}


