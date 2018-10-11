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

ll  T, n, ma1[N], ma2[N], mi1[N], mi2[N], fa[N], x;
ll ans1, ans2 ,tmp1, tmp2;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 0, n+1) ma1[i] = ma2[i] = -pw(30);
		rep(i, 0, n+1) mi1[i] = mi2[i] = pw(30);
		rep(i, 2, n+1) cin >> fa[i];
		rep(i, 1, n+1) {
			cin >> x;
			if (ma1[fa[i]] <= x) {
				ma2[fa[i]] = ma1[fa[i]];
				ma1[fa[i]] = x;
			}
			else {
				ma2[fa[i]] = max(ma2[fa[i]],x);
			}
			if (mi1[fa[i]] >= x) {
				mi2[fa[i]] = mi1[fa[i]];
				mi1[fa[i]] = x;
			}
			else {
				mi2[fa[i]] = min(mi2[fa[i]],x);
			}
		}
		ans1 = ans2 = 0;
		tmp1 = -1;tmp2 = 1;
		rep(i, 0, n+1) ans1 += max(0ll, ma1[i]), ans2 += min(0ll, mi1[i]);
		rep(i, 0, n+1) tmp1 = max(tmp1, ma2[i]), tmp2 = min(tmp2, mi2[i]);
		cout << ans1 + max(0ll, tmp1) << " " << ans2 + min(0ll, tmp2) << endl;
	} 
	return 0;
}

