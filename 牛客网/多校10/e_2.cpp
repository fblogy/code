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
const int mod = 998244353;

int ma, T, cnt[N], num[N], tmp, ans, n, inv[N], M, x, f[N], d;
vi p[N];

int add(int x, int y){
	x = (x + y) % mod;
	if (x < 0) x += mod;
	return x;
}

int mul(int a, int b){
	return 1ll * a * b % mod;
}

int qpow(int a, int b){
	int res = 1;
	while(b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int cntp, low[N], phi[N], P[N]; //f[n]为n的最小质因子，g[n]=f[n]^k，phi[n]为欧拉函数，u[n]为莫比乌斯函数，h[n]为一般积性函数 

void prime(int n) {
	phi[1]=1; //1的时候特判 
	rep(i, 2, n+1) {
		if (!low[i]) {
			P[++cntp]=i;
			low[i] = i;
			phi[i] = i - 1;
		}//质数的时候特判 
		for (int j = 1, k; j <= cntp && P[j] <= low[i] && i * P[j] <= N; j++){
			low[k = i * P[j]] = P[j];
			if (P[j] < low[i]) {
				phi[k] = phi[i] * phi[P[j]];		
			}
			else {;
				phi[k] = phi[i] * P[j];
			} /*质数次幂特判*/
		}
	}
}



int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	ma = 1e5;
	prime(ma);
	rep(i, 1, ma+1)
		for (int j = i; j <= ma; j += i) p[j].pb(i);
	inv[1] = 1;
	rep(i, 2, ma+1) inv[i] = mul(mod - mod / i, inv[mod % i]);
	x = 50; ans = x;
	rep(i, 0, sz(p[x])) ans -= phi[p[x][i]];
	rep(cas, 0, T) {
		cin >> n >> M;
		memset(num, 0, sizeof(num));
		memset(cnt, 0, sizeof(cnt));
		rep(i, 1, n+1) cin >> x, num[x]++;
		rep(i, 1, ma+1) 
			for (int j = i; j <= ma; j += i) cnt[i] += num[j];
		ans = 0;
		rep(m, 1, M+1) {
			tmp = 0;
			for(int j = sz(p[m]) - 1; j >= 0; j--) {
				d = p[m][j];
				//de(d);
				f[d] = mul(qpow(m+1, cnt[d]) - 1, inv[m]);
				//rep(i, j+1, sz(p[m])) if (p[m][i] % d == 0) f[d] = add(f[d], -f[p[m][i]]);
				tmp = add(tmp, mul(f[d], phi[d]));
			}
			//return 0;
			//de(tmp);
			ans ^= tmp;
		}
		cout << ans << endl;
	}
	return 0;
}

