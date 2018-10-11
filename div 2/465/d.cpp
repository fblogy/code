#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=100005;
const int mod=1e9+7;

int n, m;
int a[N], b[N], sum[N];
ll ans, Q, now;

ll add(ll a, ll b) { return (a + b) % mod;}

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	} 
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i], sum[i] += (a[i] == 0);
	rep(i, 1, n+1) cin >> b[i], sum[i] += (b[i] == 0);
	for(int i = n; i >= 1; i--) sum[i] += sum[i+1];
	now = 1;
	rep(i, 1, n+1) {
		if (a[i] !=0 && b[i] != 0) {
			if (a[i] > b[i]) {
				ans = add(ans, now * qpow(m, sum[i]) % mod);
			}
			if (a[i] != b[i]) break;
		}else if (a[i] == 0 && b[i] == 0){
			ans = add(ans, 1ll * (m - 1) * m / 2 % mod * qpow (m, sum[i + 1]) % mod * now % mod);
			now = now * m % mod;
		}else if (a[i] == 0) {
			ans = add(ans, (m - b[i]) * qpow (m, sum[i + 1]) % mod * now % mod);
		}else if (b[i] == 0) {
			ans = add(ans, (a[i] - 1) * qpow (m, sum[i + 1]) % mod * now % mod);
		}	
	} 
	Q = qpow (m, sum[1]);
	cout << ans * qpow(Q, mod - 2) % mod << endl;
	return 0;
}

