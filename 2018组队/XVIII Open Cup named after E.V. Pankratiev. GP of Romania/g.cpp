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
int add(int a, int b, int P) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b, int P) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b, int P) {return 1ll * a * b % P;}
int kpow(int a, int b, int P) {int r=1;for(;b;b>>=1,a=mul(a,a,P)) {if(b&1)r=mul(r,a,P);}return r;}
//----

const int N = 2e6 + 7;
const int base1 = 31;
const int base2 = 233;
const int P1 = P;
const int P2 = 998244353;

pii a[N];
int len[N], cnt[N], now, n, m, h1, h2;
__int128 ans;
string s[N];

void Manacher(pii *s,int n,int *pa){
    pa[0] = 1;
    for(int i=1,j=0;i<(n<<1)-1;++i){
        int p = i >> 1 , q = i - p , r = ((j + 1)>>1) + pa[j] - 1;
        pa[i] = r < q ? 0 : min(r - q + 1 , pa[(j<<1) - i]);
        while(0 <= p - pa[i] && q + pa[i] < n && s[p - pa[i]] == s[q + pa[i]])
            pa[i]++;
        if(q + pa[i] - 1 > r) j = i;
    }
}

ll solve(int n) {
	ll res = 0;
	Manacher(a, n, len);
	rep(i, 0, n) len[i] = len[i << 1 | 1];
	now = n-1;cnt[n-1] = 1;
	per(i, 0, n-1) {
		if (i + len[i] >= now) {
			now = i;
			cnt[i] = cnt[i+1] + 1;
		}else cnt[i] = cnt[i+1];
	}
	now = 0;res = cnt[0];
	rep(i, 1, n) {
		if (i - len[i-1] <= now) {
			now = i;
			res += cnt[i];
		}
	}
	//de(res);
	return res;
}

int main() {
//	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> s[i];
	rep(i, 1, n+1) {
		h1 = h2 = 0;
		rep(j, 1, m+1) {
			h1 = mul(h1, base1, P1);
			h2 = mul(h2, base2, P2);
			h1 = add(h1, s[i][j-1] - 'a' + 1, P1);
			h2 = add(h2, s[i][j-1] - 'a' + 1, P2);
		}
		a[i-1] = mp(h1, h2);
		//dd(h1);de(h2);
	}
	//cout << endl;
	ans = solve(n);
	//return 0;
	rep(i, 1, m+1) {
		h1 = h2 = 0;
		rep(j, 1, n+1) {
			h1 = mul(h1, base1, P1);
			h2 = mul(h2, base2, P2);
			h1 = add(h1, s[j][i-1] - 'a' + 1, P1);
			h2 = add(h2, s[j][i-1] - 'a' + 1, P2);
		}
		a[i-1] = mp(h1, h2);
	}
	ans = ans * solve(m);
	vi tmp;
	while (ans) {
		tmp.pb(ans % 10);
		ans /= 10;
	}
	reverse(all(tmp));
	rep(i, 0, sz(tmp)) cout << tmp[i];
	return 0;
}


