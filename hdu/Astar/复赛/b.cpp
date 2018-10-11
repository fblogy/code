#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 100005;
const int mod = 1e9+7;

int n, f[N], ans, T, ma, fm, l[N], r[N], inv[N], tmp;

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	x = (x + y) % mod;
	if (x < 0) x += mod;
	return x;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int cal(int l, int r, int ma) {
	if (l > r) return 0;
	return ma * (r - l + 1) - (l + r) * (r - l + 1) / 2;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T){
		cin >> n;
		ma = 0;fm = 1;ans = 0;
		rep(i, 1, n+1) cin >> l[i] >> r[i], ma = max(ma, r[i]), fm = mul(fm, r[i] - l[i] + 1);
		rep(i, 1, ma+1) {
			f[i] = 1;
			rep(j, 1, n+1) {
				f[i] = mul(f[i], cal(l[j], min(r[j], i), i + 1));
			}
			tmp = 1;
			rep(j, 1, n+1) {
				tmp = mul(tmp, cal(l[j], min(r[j], i - 1), i + 1));
			}
			ans = add(ans, add(f[i], -tmp));
		}
		cout << mul(ans, qpow(fm, mod - 2)) << endl; 
	}
	return 0;
}

