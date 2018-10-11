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
struct node {
	int o, num, pos;
} a[N], b[N];
vector<node> z;
vi ans, c;
int sum, n, m, n1, m1, x;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	a[0].o = -1;
	rep(i, 1, n+1) {
		cin >> x;
		if (x != a[n1].o) {
			a[++n1] = {x, 1, i}; 
		}else a[n1].num++; 
	}
	cin >> m;
	b[0].o = -1;
	rep(i, 1, m+1) {
		cin >> x;
		if (x != b[m1].o) {
			b[++m1] = {x, 1, i + n}; 
		}else b[m1].num++; 
	}
	if(a[n1].o == 0) z.pb(a[n1--]);
	if(b[m1].o == 0) z.pb(b[m1--]);
	while (n1 > 0 && m1 > 0) {
		per(i, a[n1].pos, a[n1].pos + a[n1].num) ans.pb(i);
		per(i, b[m1].pos, b[m1].pos + b[m1].num) ans.pb(i);
		c.pb(a[n1--].num + b[m1--].num);
	}
	while (n1 > 0) {
		per(i, a[n1].pos, a[n1].pos + a[n1].num) ans.pb(i);
		c.pb(a[n1--].num);
	}
	while (m1 > 0) {
		per(i, b[m1].pos, b[m1].pos + b[m1].num) ans.pb(i);
		c.pb(b[m1--].num);
	}
	reverse(all(ans));
	rep(i, 0, sz(ans)) cout << ans[i] << " ";
	rep(i, 0, sz(z)) {
		rep(j, z[i].pos, z[i].pos + z[i].num) cout << j << " ";
	}
	cout << endl;
	reverse(all(c));
	cout << sz(c) << endl;
	rep(i, 0, sz(c)) {
		sum += c[i];
		cout << sum << " ";
	}
	return 0;
}


