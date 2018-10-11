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

int ma, cnt[30], ans, n, tmp;
string s;
vi p[30];
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	cin >> s;
	n = sz(s);
	rep(i, 0, n) p[s[i] - 'a'].pb(i);
	s = s + s;
	rep(i, 0, 26) {
		ma = 0;
		rep(l, 1, n) {
			tmp = 0;
			memset(cnt, 0, sizeof(cnt));
			rep(j, 0, sz(p[i])) {
				cnt[s[p[i][j] + l] - 'a']++;
			}
			rep(j, 0, 26) if (cnt[j] == 1) tmp++;
			ma = max(ma, tmp);
		}
		ans += ma;
	}
	cout << 1.0 * ans / n;
	return 0;
}

