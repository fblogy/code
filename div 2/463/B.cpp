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

const int N=1000005;
const int mod=1e9+7;

int s[N][10], gg[N];
int n, q, l, r, k;

int f(int n) {
	int res = 1;
	while (n > 0) {
		if (n % 10 != 0) res *= n % 10;
		n /= 10;
	}
	return res;
}

int g(int n) {
	if (n < 10) return n;
	if (gg[n] != 0) return gg[n];
	return gg[n] = g(f(n));
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i, 1, 1000000+1) {
		rep(j, 1, 10) s[i][j] = s[i-1][j];
		s[i][g(i)]++;
	}
	cin >> q;
	rep(i, 0, q) {
		cin >> l >> r >> k;
		cout << s[r][k] - s[l-1][k] << endl;
	}
	return 0;
	
}

