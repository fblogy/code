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
int n, cnt[N], pos;
ll a[N], b[N], ans[N], s[N];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i], s[i] = s[i-1] + b[i];
	rep(i, 1, n+1) {
		pos = upper_bound(s+i, s+n+1, s[i-1] + a[i]) - s;
		cnt[i]++;
		cnt[pos]--;
		ans[pos] += a[i] - (s[pos-1] - s[i-1]);
	}
	rep(i, 1, n+1) {
		cnt[i] += cnt[i-1];
		ans[i] += cnt[i] * b[i];
	}
	rep(i, 1, n+1) cout << ans[i] << " ";
	return 0;
}


