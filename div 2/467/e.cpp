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

const int N = 105;
const int mod = 1e9+7;

int l, r, n, cnt[N], pos;
string a, b, s1, s2;
vi ans;
void shift(int x) {
	ans.pb(x);
	if (l < n - x) {
		l = x + l;
	}else l = n - l - 1;
	if (r < n - x) {
		r = x + r;
	}else r = n - r - 1;
	a = s2.substr(0, n - x);
	b = s2.substr(n - x, n);
	reverse(all(b));
	s2 = b + a;
	//de(x);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> s2 >> s1;
	rep(i, 0, sz(s1)) cnt[s1[i] - 'a']++;
	rep(i, 0, sz(s2)) cnt[s2[i] - 'a']--;
	rep(i, 0, 26) if (cnt[i]) {
		cout << -1 << endl;
		return 0;
	}
	rep(i, 0, sz(s2)) if (s2[i] == s1[0]) {
		l = r = i; break;
	}
	rep(i, 1, n) {
		rep(j, 0, n) if ((j < l || j > r) && s2[j] == s1[i]) {
			pos = j;break;
		}
		if (pos < l) {
			shift(n - pos - 1);
			shift(1);
			shift(n - r);
		}else {
			shift(n - pos - 1);
			shift(n);
			shift(n - r);
		}
		r++;
	}
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans)) cout << ans[i] << " ";
	return 0;
}

