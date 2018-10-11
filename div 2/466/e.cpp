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

const int N=100005;
const int mod=1e9+7;

int n, c, l, r;
ll a[N], s[N], f[N];
int h[N];
 
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> c;
	l = 0; r = -1;
	rep(i, 1, n+1) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	rep(i, 1, n+1) {
		f[i] = f[i-1] + a[i];
		while (l <= r && h[l] < i - c + 1) l++;
		while (l <= r && a[h[r]] >= a[i]) r--;
		h[++r] = i;
		if (l <= r && i >= c) f[i] = min(f[i], f[i - c] + s[i] - s[i - c] - a[h[l]]);
	}
	cout << f[n];
	return 0;
}

