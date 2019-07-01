#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl 
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 5e6 + 7;
string s[N], t[N];
#define ls (x << 1)
#define rs (x << 1 | 1)
int ans[200], n, seed, b[N << 1], len, ids[N], idt[N];
char a[N << 1];


void dfs(int x) {
	if ((ls << 1) <= n) dfs(ls);
	if ((rs << 1) <= n) dfs(rs);

//	if (ls > n) return;
	if ((ls << 1) > n) {
		char tt = a[ls];
		if(rs <= n) tt *= 10, tt += a[rs];
		char t2 = 0;
		if (rs <= n) t2 += a[rs];
		t2 *= 10;t2 += a[ls];
		ans[0] += max(tt, t2);
	}else{
		int l = ids[ls], r = idt[rs];
		string tmp;
		string tt = t[r];
		if(rs <= n) tt += a[rs];
		tt += a[ls];
		per(i, 0, sz(s[l])) tt += s[l][i];
		
		l = idt[ls], r = ids[rs];
		string t2 = t[l] + a[ls];
		if(rs <= n) t2 += a[rs];
		per(i, 0, sz(s[r])) t2 += s[r][i];
		int len = sz(tt), ok = 0;
		rep(i, 0, len) if (tt[i] > t2[i]) {
			break;
		}
		else if (tt[i] < t2[i]) {
			rep(j, 0, len) ans[len - j - 1] += t2[j];
			ok  = 1;
			break;
		}
		if(!ok) rep(j, 0, len) ans[len - j - 1] += tt[j];
	}
		
	
	if ((ls << 1) > n) {
		ids[x] = x; idt[x] = x;
		s[x] = t[x] = max(a[ls], a[rs]);
	}
	else {
		int l = ids[ls], r = ids[rs];
		int s1 = sz(s[l]), s2 = sz(s[r]);
		s[l] += a[ls]; s[r] += a[rs];
		if (s1 < s2) ids[x] = r;
		else if (s1 > s2) ids[x] = l;
		else {
			ids[x] = l;
			per(i, 0, s1+1) if (s[l][i] > s[r][i]) {
				ids[x] = l;
				break;
			}else if (s[l][i] < s[r][i]) {
				ids[x] = r;
				break;
			}
		}		
		l = idt[ls], r = idt[rs];
		s1 = sz(t[l]), s2 = sz(t[r]);
		t[l] += a[ls]; t[r] += a[rs];
		if (s1 < s2) idt[x] = r;
		else if (s1 > s2) idt[x] = l;
		else {
			idt[x] = l;
			rep(i, 0, s1+1) if (t[l][i] > t[r][i]) {
				idt[x] = l;
				break;
			}else if (t[l][i] < t[r][i]) {
				idt[x] = r;
				break;
			}
		}
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> seed;
	b[1] = seed;
	rep(i, 2, n+1) b[i] = (1ll * b[i-1] * 1103515245 + 12345) & (pw(31)-1);
	rep(i, 1, n+1) a[i] = (b[i] >> 16) % 9 + 1;
	dfs(1);
	rep(i, 0, 100) {
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
	len = 100;
	while (len >= 0 && ans[len] == 0) len--;
	if (len < 0) cout << 0;
	else per(i, 0, len+1) cout << ans[i];
	return 0;
}
