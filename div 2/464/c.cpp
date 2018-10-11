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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=200005;
const int mod=1e9+7;

int n, a[N], ans, d, pos, s, f, tmp;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, n+1, n+n+1) a[i] = a[i - n];
	rep(i, 1, n+n+1) a[i] += a[i - 1];
	cin >> s >> f;
	d = f - s;
	rep(i, 1, n+1) {
		tmp = ((s - i + 1) % n + n) % n;
		if (tmp == 0) tmp = n;
		if (a[i + d - 1] - a[i - 1] > ans) {
			ans = a[i + d - 1] - a[i - 1];
			pos = tmp;
		}else if (a[i + d - 1] - a[i - 1] == ans) {
			pos = min(pos, tmp);
		}	
	}
	cout << pos;
	return 0;
}

