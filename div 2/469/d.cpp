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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

ll n, q, pos;

ll get(ll n, ll pos) {
	ll mid = n / 2;
	if (n == 1) return 1;
	if (n % 2 == 1) {
		if (pos % 2 == 1) return pos / 2 + 1;
		pos = pos / 2;
		if (pos == 1) return get(mid, mid) + mid + 1;
		else return get(mid, pos - 1) + mid + 1;
	}
	if (pos % 2 == 1) return pos / 2 + 1;
	pos = pos / 2;
	return get(mid, pos) + mid;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> q;
	rep(i, 0, q) {
		cin >> pos;
		cout << get(n, pos) << endl;
	}
	return 0;
}


