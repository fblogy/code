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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 5e5 + 7;
int n, m, hs[N], ht[N], k, lpos, f[N], g[N], pow29[N];
string s, t;

void gethash(){
	rep(i, 1, n+1) hs[i] = add(mul(hs[i-1], 29), s[i-1] - 'a' + 1);
	rep(i, 1, m+1) ht[i] = add(mul(ht[i-1], 29), t[i-1] - 'a' + 1);
}

bool check(int l1, int r1, int l2, int r2) {
	int w1 = sub(hs[r1], mul(hs[l1-1], pow29[r1 - l1 + 1]));
	int w2 = sub(ht[r2], mul(ht[l2-1], pow29[r1 - l1 + 1]));
	return w1 == w2;
}

int main() {
	//freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k;
	cin >> s >> t;
	pow29[0] = 1;
	rep(i, 1, n+1) pow29[i] = mul(pow29[i-1], 29);
	gethash();
	fill_n(f, m+1, n+1);
	fill_n(g, m+1, n+1);
	lpos = k;f[0] = g[0] = k;
	rep(i, 1, min(m, k)+1) {
		while (lpos <= n && !check(lpos - i + 1, lpos, 1, i)) lpos++;
		f[i] = lpos;
		if (check(k - i + 1, k, 1, i)) f[i] = k;
		lpos = f[i];
	}
	if (k >= m){
		rep(i, m, k+1) if (check(i - m + 1, i, 1, m)) {f[m] = k; break;}
	}
	reverse(all(s));
	reverse(all(t));
	gethash();
	lpos = k;
	rep(i, 1, min(m, k)+1) {
		while (lpos <= n && !check(lpos - i + 1, lpos, 1, i)) lpos++;
		g[i] = lpos;
		if (check(k - i + 1, k, 1, i)) g[i] = k;
		lpos = g[i];
	}
	if (k >= m){
		rep(i, m, k+1) if (check(i - m + 1, i, 1, m)) {g[m] = k; break;}
	}
	rep(i, 0, min(m, k)+1) { 
		if (f[i] < n - g[m - i] + 1) {
			cout << "Yes\n";
			cout << f[i] - k + 1 << " " << n - g[m - i] + 1<< endl;
			return 0;
		}
	}
	cout << "No";
	return 0;
}
