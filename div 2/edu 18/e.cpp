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
const int P = 1e8 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 505;
ll ans, tmp;
int L[N], R[N], l, r, mid, n, a[N], p;
bool ok;
short f[P];
//unordered_set<int> s[N];

void Add(int i, int x) {
	//if (i == 1 || s[i-1].count(x)) s[i].insert(x);
	if (f[x % P] == i - 1) {
		f[x % P] = i;
		if (i == n) p = max(p, x);
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
	rep(i, 1, n+1) {
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				Add(i, j - 1);
				Add(i, a[i] / j - 1);
			}
		}
		for (int l = 1; l <= a[i]; l = r + 1) {
			r = a[i] / (a[i] / l);
			Add(i, r);
		}
	}
	rep(i, 1, n+1) 
		ans += (a[i] % (p+1) == 0 ? a[i] / (p+1) : a[i] / (p+1) + 1);
	cout << ans;
	return 0;
}


