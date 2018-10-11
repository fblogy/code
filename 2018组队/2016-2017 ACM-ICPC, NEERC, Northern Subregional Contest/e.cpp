#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int P = 1e9 + 7;
const int B = 1000007;

int add(int x, int y) {return (x + y) % P;}
int sub(int x, int y) {return (x - y + P) % P;}
int mul(int x, int y) {return 1ll * x * y % P;}
int kpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

const int N = 1e5 + 7;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int pos, n, m, x, y, cnt, w, CNT, k, po;
ll S1, sum1;
string s;
bool ok;
pii tmp, st;
vector<pii> a;
map<pii, int> M;
set<pii> S;
int get(char x) {
	if (x == 'u') return 0;
	if (x == 'd') return 1;
	if (x == 'l') return 2;
	if (x == 'r') return 3;
	return -1;
}

pii pp[N];

pii operator - (pii a, pii b) {return {a.fi - b.fi, a.se - b.se};}

int cal(pii x) { return ((x.fi * pw(28) + x.se) % (P-1) + P-1) % (P-1);}


bool check() {
	ll tmp1;
	pii tmp = *S.begin();
	tmp.fi--;tmp.se--;
	w = cal(tmp);
	tmp1 = mul(sum1, kpow(kpow(B, w), P - 2));
	return tmp1 == S1;
}

void DEL(pii x) {
	cnt--;S.erase(x);
	w = cal(x);
	sum1 = sub(sum1, kpow(B, w));
}

void ADD(pii x) {
	cnt++;S.insert(x);
	w = cal(x);
	sum1 = add(sum1, kpow(B, w));
}

int main() {
	freopen("a.in", "r", stdin);
//	freopen("easy.in","r",stdin);
//	freopen("easy.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	rep(i, 1, n+1) if (get(s[i-1]) >= 0) a.pb({get(s[i-1]), i});
	k = sz(a);
	cin >> n >> m;
	tmp = {pw(30), pw(30)};
	rep(i, 1, n+1) {
		cin >> s;
		rep(j, 1, m+1) if (s[j-1] == 'X') {
			CNT++;
			tmp = min(tmp, {i, j});
			w = cal(mp(i+1, j+1) - tmp);
			S1 = add(S1, kpow(B, w));
		}
	}
	pos = 0;x = 1; y = 1;
	st = {1, 1}; ADD(st); M[st]++;
	rep(i, 0, k) {
		while (cnt < CNT && pos < k) {
			x += dx[a[pos].fi]; y += dy[a[pos].fi];
			tmp = {x, y};
			pp[pos++] = tmp;M[tmp]++;
			if (M[tmp] == 1) ADD(tmp);
		}
		if (cnt == CNT && check()) {
			cout << "YES" << endl;
			cout << a[i].se << " " << a[pos-1].se << endl;
			return 0;
		}
		M[st]--;
		if (M[st] == 0) DEL(st);
		st = pp[i];
	}
	cout << "NO";
	return 0;
}
