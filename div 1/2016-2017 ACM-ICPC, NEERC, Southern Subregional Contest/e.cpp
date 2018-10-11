#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 105;
pii x, y, xx, yy, a[N], b[N];
int n, A, D, ans;
int cal(int i, int j) {
	x = a[i]; y = a[j];
	xx = b[i]; yy = b[j];
	if (x < y && xx > yy) return 1;
	if (x > y && xx < yy) return 1;
	if (x < y) {
		if(xx > y && yy > xx) return 2;
		if(yy < x && xx < yy) return 2;
		return 0;
	}
	swap(x, y);
	swap(xx, yy);
	if (x < y) {
		if(xx > y && yy > xx) return 2;
		if(yy < x && xx < yy) return 2;
		return 0;
	} 
	return 0; 
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> A >> D;
		a[i].fi = b[i].fi = -A;
		a[i].se = b[i].se = i;
		b[i].fi -= D;
	}
	rep(i, 1, n+1) rep(j, i + 1, n + 1) ans += cal(i, j);
	cout << ans;
	return 0;

}


