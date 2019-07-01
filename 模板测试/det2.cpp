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
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e3 + 7;
int a[N][N], n;

int det(int n) { // det(a[1..n-1][1..n-1])
	int ans=1;
	rep(i, 1, n) {
		rep(j, i+1, n) while(a[j][i]) {
			int t = a[i][i] / a[j][i];
			rep(k, i, n) a[i][k] = add(a[i][k], -mul(a[j][k], t)), swap(a[i][k], a[j][k]);
			ans = P - ans;
		}
		if(a[i][i] == 0) return 0;
		ans = mul(ans, a[i][i]);
	}
	return ans;
}

int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) 
		rep(j, 1, n+1) cin >> a[i][j];
	cout << det(n+1);
	return 0;
}


