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

int n, x, num1, num2, num3, ma, mi, a[N], mid, ans;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	ma = -pw(30); mi = pw(30);
	rep(i, 1, n+1) cin >> a[i], ma = max(ma, a[i]), mi = min(mi, a[i]);
	if (ma - mi < 2) {
		cout << n << endl; 
		rep(i, 1, n+1) cout << a[i] << " ";
	}else {
		mid = ma + mi >> 1;
		rep(i, 1, n+1) if (a[i] == ma) num1++;
		else if (a[i] == mid) num2++;
		else num3++;
		if (num2 - num2 % 2 > min(num1, num3) * 2) {
			ans = n - (num2 - num2 % 2);
			num1 += num2 / 2;
			num3 += num2 / 2;
			num2 %= 2; 
		} else {
			x = min(num1, num3);
			ans = n - x * 2;
			num1 -= x;
			num3 -= x;
			num2 += x * 2;
		}
		cout << ans << endl;
		rep(i, 0, num1) cout << ma << " ";
		rep(i, 0, num2) cout << mid << " ";
		rep(i, 0, num3) cout << mi << " "; 
	}
 	return 0;
}

