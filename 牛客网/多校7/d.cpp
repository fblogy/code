#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

//---

const int N = 100005;
const int mod = 1e9+7;

ll M, p, n, ma, ansp, ansn, now, tmp;
vi Div[N];
ll cntp, low[N], P[N]; 

void prime(int n) {
	rep(i, 2, n+1) {
		if (!low[i]) {
			P[++cntp]=i;
			low[i] = i;
		}
		for (int j = 1, k; j <= cntp && P[j] <= low[i] && i * P[j] <= N; j++){
			low[k = i * P[j]] = P[j];
		}
	}
}

int qpow(int a, ll b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return res;
}

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

bool check(int a, ll b, int p) {
	return qpow(a, b, p) == 1;
}

void solve(int p) {
	if (ma < 1) {
		ma = 1; ansn = 1; ansp = p;
	}
	n = p;now = 1;
	rep(A, 2, p) {
		if (n % (p - 1) == 0) break;
		if (!check(A, n, p)) {
			now = A; tmp = n; 
		}
		rep(i, 0, sz(Div[p-1])) {
			if (check(A, Div[p-1][i], p)) {
				n = lcm(n, Div[p-1][i]);
				break;
			}
		}
	} 
	if (now > ma) {
		ma = now;
		ansn = tmp;
		ansp = p;
	}
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> M;
	prime(M);
	rep(i, 1, M+1)
		for(int j = i; j <= M; j += i) Div[j].pb(i);
	ma = 0;
	rep(i, 1, cntp+1) {
		solve(P[i]);
	}
	cout << 1 << " " << ansn << " " << 0 << " " << ansp;
	return 0;
}

