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
int P;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 1e5 + 7;
int n, s1, s2, a[N], b[N];
unordered_map<int, int> M;

int inv(int x) {return kpow(x, P - 2);}

void solve(int d) {
	int a1 = mul(sub(s1, mul(1ll * n * (n - 1) / 2 % P, d)), inv(n));	
	if (!M.count(a1)) return;
	int tmp = mul(n, mul(a1, a1));
	int x = 1ll * n * (n - 1) % P * add(mul(a1, d), mul(mul(2 * n - 1, mul(d, d)), inv(6))) % P;
	tmp = add(tmp, x);
	if (tmp != s2) return;
	b[1] = a1;
	rep(i, 2, n+1) b[i] = add(b[i-1], d);
	sort(b + 1, b + n + 1); 
	rep(i, 1, n+1) if (b[i] != a[i]) return;
	cout << a1 << " " << d; 	
	exit(0);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> P >> n;
	rep(i, 1, n+1) cin >> a[i], s1 = add(s1, a[i]), s2 = add(s2, mul(a[i], a[i])), M[a[i]] = 1;
	sort(a + 1, a + n + 1);
	if (n == 1) {
		cout << a[1] << " " << 0;
		return 0;
	}
	rep(i, 2, n+1) {
		solve(sub(a[i], a[1]));
		solve(sub(a[1], a[i]));
	}
	cout << -1;
	return 0;
}


