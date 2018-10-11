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
//---

const int N=105;
//const int mod=1e9+7;

int a[N], b[N], mod[N], x[N], num, ma, n, m, tmp, pos, T, c[N];
ll M, ans;

ll add(ll x, ll y) {
	ll res = x + y;
	if (res > M) res -= M;
	return res;
}

ll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int phi(int n) {
	int x = 2, nn = n;
	while (x * x <= n) {
		if (n % x == 0) nn = nn / x * (x - 1);
		while (n % x == 0) n /= x;
		x++;
	}
	if (n > 1) nn = nn / n * (n - 1);
	return nn;
}

ll CRT() {
	ll res = 0, MI;
	//de(M);
	//return 0;
	rep(i, 1, num+1) {
		MI = M / mod[i];
		res = add(res, x[i] * MI % M * qpow(MI, phi(mod[i]) - 1, mod[i]) % M);
	}
	return res;	
}


ll work() {
	M = 1; num = 0;
	rep(i, 2, 100) { 
		ma = 0;
		rep(j, 1, m+1) {
			tmp = 0;
			while (b[j] % i == 0) b[j] /= i, tmp++;
			if (tmp > ma) {
				ma = tmp;
				pos = j;
			}
		}
		if (ma > 0) {
			mod[++num] = pow(i, ma);
			x[num] = a[pos] % mod[num];
			M *= mod[num];
		}
	}
	//de(mod[2]);
	//return 0;
	return CRT();
}

bool check(int x) {
	rep(i, 1, m+1) if (x % c[i] != a[i]) return 0;
	return 1;	
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		//cin >> n >> m;
		cin >> m; 
		rep(i, 1, m+1) cin >> b[i], c[i] = b[i];
		rep(i, 1, m+1) cin >> a[i];
	//de(phi(6));
		ans=work();
		//rep(i, 1, m+1) de(mod[i]);
		if (ans == 0) ans = M; 
		de(ans);
		/*if (check(ans) && n >= ans) cout << (n - ans) / M + 1 << endl;
		else cout << 0 << endl;*/ 
	}
	return 0;
}

