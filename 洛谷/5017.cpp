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
//const int P = 1e9 + 7;
//----

const int N = 110005;
int n, m, f[N], a[N], s[N], ma, l, r, ans;
struct P{
	int x, y;
	P(int x = 0, int y = 0): x(x), y(y){}
	P operator - (const P & c) {
		return P (x - c.x , y - c.y);
	}
} p[N];

int cross(const P &a, const P &b) {return a.x * b.y - a.y * b.x;}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i];
	sort(a + 1, a + n + 1);
	int t = a[1]; a[1] = 0;
	rep(i, 2, n+1) {
		a[i] -= t;
		if (a[i] > a[i-1] + 2 * m) {
			t += a[i] - (a[i-1] + 2 * m);
			a[i] = a[i-1] + 2 * m;
		}	
	}
	rep(i, 1, n+1) s[a[i]]++, ma = max(ma, a[i]);
	ma += 2 * m;
	rep(i, 1, ma+1) s[i] += s[i-1];
	l = 0; r = -1;
	rep(i, 0, ma+1) {
		if (i - m >= 0) {
			P tmp = P(s[i-m], f[i-m]);
			while (r - l + 1 >= 2 && cross(p[r] - p[r-1], tmp - p[r]) <= 0) r--;
			p[++r] = tmp;			
		}
		while (l < r && p[l+1].y - p[l].y <= i * (p[l+1].x - p[l].x)) l++;
		if (l <= r) f[i] = p[l].y + (s[i] - p[l].x) * i;
		else f[i] = s[i] * i;
	}
	ans = f[ma];
	rep(i, 1, n+1) ans -= a[i];
	cout << ans << endl;
	return 0;
}


