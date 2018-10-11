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

int fa[N], a[N], u, v, ans, cnt[31], T , n, m, w;
vi s[N];

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	return (x + y) % mod;
}

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
} 

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		ans = 0;
		rep(i, 1, n+1) fa[i] = i, s[i].clear();
		rep(i, 1, n+1) cin >> a[i];
		rep(i, 1, m+1) {
			cin >> u >> v;
			u = get(u); v = get(v);
 			fa[u] = v;
		}
		rep(i, 1, n+1) {
			s[get(i)].pb(a[i]);
		} 
		rep(i, 1, n+1) {
			memset(cnt, 0, sizeof(cnt));
			sort(all(s[i]));
			rep(j, 0, sz(s[i])) {
				w = s[i][j];
				rep(k, 0, 31) if (pw(k) & w) {
					ans = add(ans, mul(mul(pw(k), cnt[k]), w));
					cnt[k]++;
				}
			}
		}
		cout << ans << endl;
	}
		
	return 0;
}

