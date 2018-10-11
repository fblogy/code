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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 1e5 + 7;
ll n, d, b, a[N], s[N], pr, pl, ans1, ans2, suml, sumr, usel, user; 

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(0);
	cin >> n >> d >> b;
	rep(i, 1, n+1) cin >> a[i], s[i] = s[i-1] + a[i];
	rep(t, 1, n / 2 +1) {
		pr = min(n, t * d + t);
		pl = max(1ll, n - t + 1 - t * d);
		suml = s[pr] - s[0];
		sumr = s[n] - s[pl - 1];
		if (suml - usel >= b) usel += b;
		else ans1++;
		if (sumr - user >= b) user += b;
		else ans2++;
	}
	cout << max(ans1, ans2);
	return 0;
}


