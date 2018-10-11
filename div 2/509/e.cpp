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
int n, a[N], b[N], cnt[N], num, t;
vector<pii> ans;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	priority_queue<int> q;
 	rep(i, 1, n) {
		cin >> a[i] >> b[i];
		cnt[a[i]]++;
		if (b[i] != n) {
			cout << "NO";
			return 0;
		}
	} 
	rep(i, 1, n) if (cnt[i] == 0) q.push(-i);
	rep(i, 1, n) if (cnt[i] > 0) {
		num = cnt[i] - 1;
		if(num == 0) {ans.pb(mp(i, n));continue;}
		vi tmp;
		while (!q.empty()) {
			t = -q.top();q.pop();
			if (t > i) break;
			tmp.pb(t);
			num--;
			if (num == 0) break;
		}
		if (num != 0) {
			cout << "NO";
			return 0;
		}
		rep(i, 0, sz(tmp) - 1) ans.pb(mp(tmp[i], tmp[i + 1]));
		ans.pb(mp(i, tmp[0]));
		ans.pb(mp(tmp[sz(tmp) - 1], n));
	}
	cout << "YES" << endl;
	rep(i, 0, sz(ans)) cout << ans[i].fi << " " <<  ans[i].se << endl;
	return 0;
}


