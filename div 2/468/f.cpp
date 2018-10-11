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

int n, m, l, r, a[N], f[N], g[N], p[N], pos, len, ans;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> l >> r;
		a[l]++; a[r+1]--;
	}
	rep(i, 1, m+1) {
		a[i] += a[i-1];
	}
	len = 0;
	rep(i, 1, m+1) {
		pos = upper_bound(p , p + len + 1, a[i]) - p;
		if (pos > len) {
			p[++len] = a[i];
		}else {
			p[pos] = a[i];
		}
		f[i] = pos;
	}
	memset(p, 0, sizeof(p));
	reverse(a + 1, a + m + 1);
	len = 0;
	rep(i, 1, m+1) {
		pos = upper_bound(p , p + len + 1, a[i]) - p;
		if (pos > len) {
			p[++len] = a[i];
		}else {
			p[pos] = a[i];
		}
		g[i] = pos;
	}
	rep(i, 1, m+1) ans = max(ans, f[i] + g[m - i + 1] - 1);
	cout << ans;
	return 0;
}

