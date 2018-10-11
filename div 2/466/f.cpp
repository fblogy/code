#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=100005;
const int mod=1e9+7;
const int BSZ = 2154;

int B, bl[N], br[N], id[N], tid, mex[N], cnt[N * 2], l, r, now, qnum, cnum, a[N], ans[N], n, m, op, pos, x, pre, tmp[N];
map<int, int> M;

struct qnode{
	int l, r, cnum, qnum;
} q[N];

struct cnode{
	int pos, pre, now;
} c[N];

void init(){
	B = (n - 1) / BSZ + 1;
	rep(i, 0, B) {
		bl[i] = BSZ * i;
		br[i] = min(n, bl[i] + BSZ);
		rep(j, bl[i], br[i]) id[j] = i;
	}
}

int ID(int x) {
	if (M.count(x)) return M[x];
	return M[x] = ++tid;
}

bool cmp(qnode a, qnode b){
	if (id[a.l] != id[b.l]) return id[a.l] < id[b.l];
	if (id[a.r] != id[b.r]) return id[a.r] < id[b.r];
	return a.cnum < b.cnum;
}

void upd(int x, int d){
	mex[cnt[x]]--;
	cnt[x] += d;
	mex[cnt[x]]++;
}

void solve(){
	l = -1; r = -1; now = 0;
	rep(i, 0, qnum) {
		while (l > q[i].l) {l--; upd(a[l], 1);}
		while (r < q[i].r) {r++; upd(a[r], 1);}
		
		while (l < q[i].l) {upd(a[l], -1); l++;}	
		while (r > q[i].r) {upd(a[r], -1); r--;}
		
		while (now < q[i].cnum) {
			now++; 
			if (c[now].pos >= l && c[now].pos <= r) {
				upd(c[now].pre, -1);
				upd(c[now].now, 1);
			}
			a[c[now].pos] = c[now].now;
		}
		while (now > q[i].cnum) {
			if (c[now].pos >= l && c[now].pos <= r) {
				upd(c[now].now, -1);
				upd(c[now].pre, 1);
			}
			a[c[now].pos] = c[now].pre;
			now--;
		}
		rep(j, 1, n+10) if (!mex[j]) {
			ans[q[i].qnum] = j;
			break;
		}
	}

}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 0, n) cin >> a[i], a[i] = ID(a[i]), tmp[i] = a[i];
	init();
	rep(i, 0, m) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r;
			l--; r--;
			q[qnum] = {l, r, cnum, qnum};
			qnum++;
		}else {
			cin >> pos >> x;
			pos--;
			pre = tmp[pos];
			tmp[pos] = ID(x);
			c[++cnum] = {pos, pre, tmp[pos]};
		}
	}
	sort(q, q + qnum, cmp);
	solve();
	rep(i, 0, qnum) cout << ans[i] << endl;
	return 0;
}

