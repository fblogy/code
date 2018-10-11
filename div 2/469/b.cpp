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

int n, m, s1, s2, a[N], b[N], p1, p2, ans;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, m+1) cin >> b[i];
	p1 = p2 = 1;
	s1 = a[1]; s2 = b[1];
	while (1) {
		while (s1 != s2) {
			if (s1 < s2) {
				s1 += a[++p1];
			}else{
				s2 += b[++p2];
			}
		}
		ans++;
		if (p1 == n) break;
		s1 += a[++p1];
		s2 += b[++p2];
	}
	cout << ans;
 	return 0;
}

