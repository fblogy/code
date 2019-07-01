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
const db pi = acos(-1);
int n, m, ang, p, pos;
int a[N];
db x[N], y[N], ans[N], sum, nowx, nowy;

int main() {
	freopen("green.in","r",stdin);
	freopen("green.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> n >> m >> ang;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, m+1) cin >> x[i] >> y[i], y[i] += x[i] * tan(1.0 * ang / 180 * pi);
	p = max_element(a+1, a+n+1) - a;
	m = max_element(y+1, y+m+1) - y; 
	//de(p);de(m);de(y[m] - y[1]);
	ans[p] = x[m];sum = a[p];
	pos = 2;
	nowx = x[1]; nowy = y[1];
	rep(i, 1, n+1) if (i != p){
		ans[i] = nowx;
		while (pos <= m && y[pos] < nowy + a[i]) pos++;
		if (pos <= m) {
			nowy += a[i];
			nowx = x[pos-1] + (nowy - y[pos-1]) / ((y[pos] - y[pos-1]) / (x[pos] - x[pos-1]));
			sum += a[i];
		}else {
			sum += y[m] - nowy;
			rep(j, i+1, n+1) ans[j] = x[m];
			break;
		}
	}
	cout << sum  << endl;
	rep(i, 1, n+1) cout << ans[i] << endl;
	return 0;
}


