// 构造原图和补图直径最小值为k 
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

int n, k;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	if (n <= 3) {
		cout << -1;
		return 0;
	}
	if (n == 4) {
		if (k != 3) {
			cout << -1;
			return 0;
		}
		cout << 3 << endl;
		rep(i, 1, 4) cout << i << " " << i+1 << endl;
		return 0;
	}
	if (k == 2){
		cout << n-1 << endl;
		rep(i, 1, n) cout << i << " " << i+1 << endl;
	}else if (k == 3) {
		cout << n-1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 3 << endl;
		rep(i, 4, n+1) cout << 3 << " " << i << endl;
	}else cout << -1;
	return 0;
}


