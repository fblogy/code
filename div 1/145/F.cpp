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

int n, m, p, L, R, c, tmp[30], cnt;
string s;



struct Seg{
#define ls (now << 1)
#define rs (ls | 1) 
	static const int N = 1e5 + 7;
	int tr[N * 4][30], tip[N * 4];
	void up(int now) {
		rep(i, 0, 26) tr[now][i] = tr[ls][i] + tr[rs][i];
	}
	
	void build(int l, int r,int now) {
		assert(l <= r && l > 0 && r <= n);
		tip[now] = -1;
		if (l == r) {
			tr[now][s[l-1] - 'a'] = 1;
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(now);
	} 
	
	void down(int l, int r, int now) {
		if (tip[now] == -1) return;
		assert(tip[now] >= 0 && tip[now] < 26);
		tip[ls] = tip[rs] = tip[now];
		rep(i, 0, 26) tr[ls][i] = tr[rs][i] = 0;
		int mid = l + r >> 1;
		tr[ls][tip[now]] = mid - l + 1;
		tr[rs][tip[now]] = r - mid;
		tip[now] = -1;
	}
	
	void change(int L, int R, int l, int r, int now, int c) {
		assert(l <= r && l > 0 && r <= n);
		if (l != r) down(l, r, now);
		if (L <= l && R >= r) {
			rep(i, 0, 26) tr[now][i] = 0;
			tr[now][c] = r - l + 1;
			tip[now] = c;
			return;
		}
		int mid = l + r >> 1;
		if (L <= mid) change(L, R, l, mid, ls, c);
		if (R > mid) change(L, R, mid + 1, r, rs, c);
 		up(now);
	 }
	 
	 void qry(int L, int R, int l, int r, int now) {
	 	assert(l <= r && l > 0 && r <= n);
	 	if (l != r) down(l, r, now);
	 	if (L <= l && R >= r) {
			rep(i, 0, 26) tmp[i] += tr[now][i];
			return; 
		}
		int mid = l + r >> 1;
		if (L <= mid) qry(L, R, l, mid, ls);
		if (R > mid) qry(L, R, mid + 1, r, rs); 
	 }
} seg;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	cin >> s;
	seg.build(1, n, 1);
	//rep(i, 0, 26) cout << seg.tr[1][i] << " ";
	rep(i, 1, m+1) {
		cin >> L >> R;
		rep(i, 0, 26) tmp[i] = 0;
		seg.qry(L, R, 1, n, 1);
		cnt = 0;
		//rep(i, 0, 26) cout << tmp[i] << " ";
		rep(i, 0, 26) if (tmp[i] & 1) cnt++, c = i;
		if (cnt > 1) continue;
		if (cnt == 1 && (R - L + 1) % 2 == 0) continue;
		if (cnt == 0 && (R - L + 1) % 2 == 1) continue;
		p = L;
		rep(i, 0, 26) {
			if (tmp[i] > 1) {
				assert(p <= p + tmp[i] / 2 - 1);
				assert(p + tmp[i] / 2 - 1 <= n);
				seg.change(p, p + tmp[i] / 2 - 1, 1, n, 1, i);
			}
			p += tmp[i] / 2;
		}
		if (cnt == 1) {seg.change(p, p, 1, n, 1, c); p++;}
		per(i, 0, 26) {
			if (tmp[i] > 1) {
				assert(p <= p + tmp[i] / 2 - 1);
				assert(p + tmp[i] / 2 - 1 <= n);
				seg.change(p, p + tmp[i] / 2 - 1, 1, n, 1, i);
			}
			p += tmp[i] / 2;
		}
	}
	rep(i, 1, n+1) {
		rep(i, 0, 26) tmp[i] = 0;
		seg.qry(i, i, 1, n, 1);
		rep(i, 0, 26) if (tmp[i] == 1) cout << char(i + 'a');
	}
	return 0;
}


