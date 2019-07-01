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
//----

const int N = 1 << 18;
int a[N], cnt[N], T, k, P, v[10], len;
ll ans;
int A, B, C, ss, ok;
int main() {
	freopen("a.in","r",stdin);
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	P = pw(17) - 1;
	for (int s = 3; (s * s + 1) / 2 <= 1e9; s += 2) {
		len = 0;
		ss = s;
		for (int i = 3; i * i <= ss; i++) {
			if (ss % i == 0) v[++len] = i;
			while (ss % i == 0) ss /= i;
		}
		if (ss > 1) v[++len] = ss;
		for (int t = 1; t < s && (s * s + t * t) / 2 <= 1e9; t += 2) {//if (__gcd(s, t) == 1){
			ok = 1;
			rep(i, 1, len+1) if (t % v[i] == 0) {ok = 0; break;}
			if (!ok) continue;
			A = s * t;
			B = (s * s - t * t) / 2;
			//C = (s * s + t * t) / 2;
			A > B ? cnt[A & P]++ : cnt[B & P]++;
		}
	}
	rep(cas, 0, T) {
		cin >> k;
		ans = 0;
		rep(i, 0, pw(k)) cin >> a[i];
		rep(i, 0, P+1) ans += 1ll * a[i % pw(k)] * cnt[i];
		cout << ans << endl;
	}
	return 0;
}


