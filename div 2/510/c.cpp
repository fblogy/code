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
int n, a[N], p, p2, num;
vi v0;
vector<pii> v1;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i];
		if (a[i] == 0) v0.pb(i);
		if (a[i] <0) v1.pb(mp(a[i], i));
	}
	if (sz(v1) % 2 == 1) {
		sort(all(v1));
		p = v1[sz(v1) - 1].se;
		rep(i, 0, sz(v0)) cout << 1 << " " << v0[i] << " " << p << endl, num++;
		if (num == n-1) return 0;
		cout << 2 << " " << p << endl;
		rep(i, 1, n+1) if (i != p && a[i] != 0) {p2 = i;break;}
		rep(i, 1, n+1) if (i != p && i != p2 && a[i] != 0) cout << 1 << " " << i << " " << p2 << endl;
	}else {
		if (sz(v0) > 0) {
			p = v0[0];
			rep(i, 1, sz(v0)) cout << 1 << " " << v0[i] << " " << p << endl, num++;
			if (num == n-1)  return 0;
			cout << 2 << " " << p << endl;
			rep(i, 1, n+1) if (i != p && a[i] != 0) {p2 = i;break;}
			rep(i, 1, n+1) if (i != p && i != p2 && a[i] != 0) cout << 1 << " " << i << " " << p2 << endl;
		}else {
			p2 = 1;
			rep(i, 1, n+1) if (i != p2) cout << 1 << " " << i << " " << p2 << endl;
		}
	}
	return 0;
}


