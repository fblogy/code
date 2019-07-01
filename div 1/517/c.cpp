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

const int N = 1e5 +7;
int a[N], n, p[10], m;
struct node{
	int x, y, z;
};

vector<node> ans;

void ADD(node x) {
	ans.pb(x);
	a[x.x]^=1;
	a[x.y]^=1;
	a[x.z]^=1;
}

int count (){
	int res = 0;
	rep(i, 1, n+1) res += a[i];
	return res;
}

bool solve(int o) {
	int cnt = count();
	if (o == 0) {
		m = 0;
		rep(i, 1, n+1) if (a[i] == 1){
			p[++m] = i;
			if (m == 3) {
				m = 0;
				ADD({p[1], p[2], p[3]});
			}
		}
		return 1;
	}else if (o == 2) {
		if (cnt == 2) {
			if (n <= 3) return 0;
			if (n == 4) {
				if (a[1] == 1 && a[2] == 1) return 0;
				if (a[3] == 1 && a[4] == 1) return 0;
				if (a[1] == 1 && a[4] == 1) ADD({1, 2, 4});
				int p1, p2;
				rep(i, 1, n+1) if (a[i] == 0) {p1 = i;break;}
				rep(i, 1, n+1) if (a[i] == 0) p2 = i;
				ADD({p1, p1+1, p2});
				solve(0);
				return 1;
			}else if (n >= 5) {
				m = 0;
				rep(i, 1, n+1) if (a[i] == 0){
					p[++m] = i;
					if (m == 3) {
						m = 0;
						ADD({p[1], p[2], p[3]});
						break;
					}
				}
			}
		}
		int p1, p2;
		rep(i, 1, n+1) if (a[i] == 1) {p1 = i;break;}
		rep(i, 1, n+1) if (a[i] == 1) p2 = i;
		rep(i, 1, n+1) if (a[i] == 1 && i != p1 && i != p2) {
			ADD({p1, i, p2});
			break;
		}
		rep(i, 1, n+1) if (a[i] == 1) {
			ADD({p1, i, p2});
			break;
		}
		solve(0);
		return 1;
	}else {
		if (n <= 4) return 0;
		int p1, p2;
		rep(i, 1, n+1) if (a[i] == 1) {p1 = i;break;}
		rep(i, 1, n+1) if (a[i] == 1) p2 = i;
		rep(i, 1, n+1) if (a[i] == 1 && i != p1 && i != p2) {
			ADD({p1, i, p2});
			break;
		}
		rep(i, 1, n+1) if (a[i] == 1) {
			ADD({p1, i, p2});
			break;
		}
		return solve(2);
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	int cnt = count();
	bool ok = solve(cnt % 3);
	if (ok) {
		cout << "YES" << endl;
		cout << sz(ans) << endl;
		rep(i, 0, sz(ans)) cout << ans[i].x << " " << ans[i].y <<" " << ans[i].z << endl;
	}else cout << "NO";
	return 0;
}


