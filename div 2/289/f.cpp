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

const int N = 505;
int a[N], n, f[N][N];
//unordered_map<int, int> f[N][N];

int work(int l, int r) {
	if (l >= r) return 1;
	if (f[l][r] != -1) return f[l][r];
	int res = 0;
	rep(i, l, r+1) {
		if (i + 1 > r || a[l] < a[i+1]) res = add(res, mul(work(l+1, i), work(i+1, r)));
	}
	return f[l][r] = res;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	memset(f, -1, sizeof(f));
	rep(i, 1, n+1) cin >> a[i];
	cout << work(2, n) << endl;
	//rep(i, 2, n+1) rep(j, i, n+1) dd(i),dd(j),de(f[i][j]);
	return 0;
}


