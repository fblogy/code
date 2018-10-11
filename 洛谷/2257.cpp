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
typedef unsigned int uint;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < P) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 1e7 + 7;
int n, m, M, f[N], p[N], T, u[N], G[N];
ll ans;


void prime(int n) {
    u[1] = 1;
    rep(i, 2, n+1) {
        if (!f[i]) {
            p[++M] = i;
            f[i] = i;
            u[i] = -1;
        }
        for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= N; j++){
            f[k = i * p[j]] = p[j];
            if (p[j] < f[i]) {
                u[k] = u[i] * u[p[j]]; 
            }else {
                u[k] = 0;
            }
        }
    }
    rep(i, 1, M+1) 
		for (int j = p[i], k = 1; j <= n; j += p[i], k++) G[j] += u[k];
	rep(i, 1, n+1) G[i] = G[i] + G[i - 1];
}


int main() {
	freopen("a.in","r",stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    n = 1e7;
    prime(n);
    cin >> T;
    rep(cas, 0, T) {
		cin >> n >> m;
		ans = 0;
		for (int l = 1, r; l <= min(n, m); l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			ans += 1ll * (G[r] - G[l - 1]) * (n / l) * (m / l);
		}
		cout << ans << endl;
    }
    return 0;
}
