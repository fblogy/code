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

const int N = 1e5 + 7;
struct node{
	ll len, cnt;
};

map<pii, node> F;
int p[N], m, w[N];
ll a, b, now;
bool isp[N];
string ss[N], ans;

void getprime(){
	rep(i, 2, 10000) if (!isp[i]) {
		p[++m] = i;
		int x = i; while (x) {w[m]++; ss[m] += char(x % 10 + '0'); x /= 10;}
		reverse(all(ss[m]));
		for (int j = i + i; j <= 10000; j += i) isp[j] = 1;
	}
}

node cal(int i, int s) {
	if (s < p[i]) return {0, 0};
	if (s == p[i]) return {4 + w[i], 1};
	node res;
	pii x = {i, s};
	if (F.count(x)) return F[x];
	node tmp1 = cal(i+1, s);
	node tmp2 = cal(i+1, s - p[i]);
	res.len = tmp1.len + tmp2.len + tmp2.cnt * (2 + w[i]);
	res.cnt = tmp1.cnt + tmp2.cnt;
	return F[x] = res;
} 

void solve(ll l, ll r, int s, int i, string pre) {
	if (l > r) return;
	if (s < p[i]) return;

	if (s == p[i]) {
		pre += ss[i] + "], ";
		rep(j, l, r+1) ans += pre[j-1];
		return; 
	}
   	node tmp = cal(i + 1, s - p[i]);
	ll len = tmp.len + tmp.cnt * (2 + w[i] + sz(pre) - 1);
	if (len >= l) {
		solve(l, min(len, r), s - p[i], i+1, pre + ss[i] + ", ");
		if (r > len) solve(1, r - len, s, i+1, pre);
	}else {
		solve(l - len, r - len, s, i + 1, pre);
	}
}

int main() {
//	freopen("a.in","r",stdin);
	freopen("list.in","r",stdin);
    freopen("list.out","w",stdout);	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> a >> b;
	getprime();
	rep(i, 2, 10000) {
		if (now > 1e18) break;
		node tmp = cal(1, i);
		if (now + tmp.len >= a) {
			ll L = max(now+1, a) - now;
			ll R = min(now + tmp.len, b) - now;
			solve(L, R, i, 1, "[");
		}
		now += tmp.len;
		if (now >= b) break;
	}
	cout << ans;
	return 0;
}


