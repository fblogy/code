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
int P;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 2;
ll l, r, L, R, mid, k, pos, cnt, x;

struct Mat{
	ll r[N][N];
	Mat(){memset(r, 0, sizeof(r));}
	Mat operator * (Mat b) {
		Mat c;
		rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) c.r[i][j] = add(c.r[i][j], mul(r[i][k], b.r[k][j]));
		return c;
	}
};

Mat kpow(Mat a, ll k) {
	Mat b;
	rep(i, 0, N) b.r[i][i] = 1;
	for(; k; k >>= 1, a = a * a) if (k & 1) b = b * a;
	return b;
}

bool check(ll mid) {
	return R / mid - (L - 1) / mid >= k;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> P >> L >> R >> k;
	for (ll i = 1; i <= R; i = r + 1) {
		r = R / (R / i);
		cnt = R / i;
		if (cnt >= k) {
			cnt -= k;
			x = (L - 1) / (cnt + 1) + 1;
			if (x <= r) pos = r;
			
		}
	}
	Mat a;
	a.r[0][0] = a.r[0][1] = 1;
	a.r[1][0] = 1;
	if (pos <= 2) cout << 1 % P;
	else {
		a = kpow(a, pos - 2);
		cout << add(a.r[0][0], a.r[0][1]);
	}
	return 0;
}


