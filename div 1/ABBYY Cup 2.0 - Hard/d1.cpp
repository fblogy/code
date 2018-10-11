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

const int N = 10;
int h[N], r[N], c[N][N], a[30], n, s, tmp, p[10], cnt, num;
bool use[30], ok;

unordered_map<int, int> M[5];

void dfs(int x, int y) {
	if (y > n) {x++; y = 1;}
	if (x == n) {
		rep(j, 1, n+1) {
			ok = 0;
			rep(i, 0, n*n) if (!use[i] && a[i] + h[j] == s) {
				use[i] = 1; c[n][j] = a[i]; p[j] = i;
				ok = 1;
				break;
			}
			if (!ok) {
				rep(i, 1, j) use[p[i]] = 0;
				return;
			}
		}
		
		tmp = 0;
		rep(i, 1, n+1) tmp += c[i][i];
		if (tmp != s) {
			rep(i, 1, n+1) use[p[i]] = 0;
			return;		
		}
		tmp = 0;
		rep(i, 1, n+1) tmp += c[i][n - i + 1];
		if (tmp != s) {
			rep(i, 1, n+1) use[p[i]] = 0;
			return;		
		}
		cout << s << endl;
		rep(i, 1, n+1) {
			rep(j, 1, n+1) cout << c[i][j] << " "; 
			cout << endl;
		}
		//cout << num << endl;
		exit(0);
	} 
	//if (x == 3 && y == 4) num++;
	set<int> S;
	int cnt = 0;
	rep(i, 0, n*n) if (!use[i]) {
		if (y == n && a[i] + r[x] != s) continue;
		if (x == n && a[i] + h[y] != s) continue;
		if (S.count(a[i]) || !M[n - y].count(s - a[i] - r[x]) || !M[n - x].count(s - a[i] - h[y])) continue;
		use[i] = 1;
		S.insert(a[i]);
		r[x] += a[i];
		h[y] += a[i];
		c[x][y] = a[i];
		dfs(x, y+1);
		r[x] -= a[i];
		h[y] -= a[i];
		use[i] = 0;
		cnt++;
		if (cnt > 11) break;
		if (y == n) break;
		if (x == n) break;
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setpreNScision(2);
	cin >> n;
	rep(i, 0, n*n) cin >> a[i], s += a[i];
	sort(a+1, a+n+1);
	rep(i, 0, pw(n*n)) {
		tmp = 0;cnt = 0;
		rep(j, 0, n*n) if (pw(j) & i) tmp += a[j], cnt++;
		if (cnt > 4) continue;
		M[cnt][tmp] = 1;
	}
	s /= n;
	dfs(1, 1);
	return 0;
}


