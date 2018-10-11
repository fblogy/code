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

const int N = 100005;
const int mod = 1e9+7;

ll loop, k, d, t, w, ans, ans2;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> k >> d >> t;
	if (k % d == 0) cout << t;else {
		loop = k / d * d + d;
		t *= 2;
		w = k + loop;
		ans = t / w * loop;
		t = t % w; 
		if (t <= 2 * k) {
			ans += t / 2;
			ans2 = t % 2;
		}else {
			ans += t - k;
		}
		cout << ans;
		if (ans2) cout << ".5";
	}
	return 0;
}

