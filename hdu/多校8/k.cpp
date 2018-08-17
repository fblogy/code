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
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 22;
const int mod = 1e9+7;

int n, m, k, T, num, tmp, w[N];
string s[N];
ll jc[N];
ull dp[N][1 << 12];
ull ans[N];

void upd(ull &x, ull y) {
	x += y; 
}

void print(__int128 x) {
	string s;
	if (x == 0) cout << 0 << endl;
	else {
		while (x) s += x % 10 + '0', x /= 10;
		reverse(all(s));
		cout << s << endl;
	}
}

int main(){
	freopen("k.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	jc[0] = 1;rep(i, 1, 13) jc[i] = jc[i-1] * i;
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		rep(i, 1, k+1) ans[i] = 0;
		rep(i, 0, n) cin >> s[i];
		rep(i, 1, m+1) {
			w[i] = 0;
			rep(j, 0, n) if (s[j][i-1] == 'Q') w[i] |= 1 << j;
		}
		rep(mask1, 0, 1 << n) {
			dp[0][0] = 1;
			rep(i, 1, m+1) {
				tmp = w[i];
				for (int mask2 = mask1; mask2 >= 0; mask2 = (mask2-1) & mask1) {
					if (dp[i-1][mask2]) {
						if ((tmp & mask1) == tmp) upd(dp[i][mask2], dp[i-1][mask2]);
						/*rep(l, 0, n) if (s[l][i - 1] == 'Q' && !(1 << l & mask2) && (1 << l & mask1)) {
							upd(dp[i][mask2 | (1 << l)], dp[i-1][mask2]);
						}*/
						for (unsigned dif = (mask1 ^ mask2) & tmp; dif; dif &= dif - 1) {
              				unsigned bit = dif & -dif;
              				upd(dp[i][mask2 | bit],dp[i-1][mask2]);
            			}
						dp[i-1][mask2] = 0;
					}
					if (mask2 == 0) break;
				}
			}
			ans[__builtin_popcount(mask1)] += dp[m][mask1];
			for (int mask2 = mask1; mask2 >= 0; mask2 = (mask2-1) & mask1) {
				dp[m][mask2] = 0;
				if (mask2 == 0) break;
			}
		}
		rep(i, 1, k+1) print(__int128(ans[i]) * jc[i]);	
	}
	return 0;
}

