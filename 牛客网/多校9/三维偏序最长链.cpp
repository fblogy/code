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

const int N = 100005;
const int mod = 1e9+7;

int l1, r1, ma, x, y, o, tr[N * 4], p, n, ans;

struct node {
	int x, y, z, ma;
} a[N];

void change(int l, int r, int now){
	if (l1 <= l && r <= r1) {
		if (o) tr[now] = max(ma,tr[now]);
		else tr[now] = 0;
		return;
	}
	int mid = l + r >> 1;
	if (l1 <= mid) change(l, mid, now * 2);
	if (r1 > mid) change(mid+1, r, now * 2 + 1);
	tr[now] = max(tr[now * 2], tr[now * 2 + 1]);
}

void ask(int l, int r, int now){
	if (l1 <= l && r <= r1) {
		ma = max(ma, tr[now]);
		return;
	}
	int mid = l + r >> 1;
	if (l1 <= mid) ask(l, mid, now * 2);
	if (r1 > mid) ask(mid+1, r, now * 2 + 1);
}

bool cmpx(node a, node b) {
	return a.x < b.x;
}

bool cmpy(node a, node b) {
	return a.y < b.y;
}

void CDQ(int l, int r){
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid);
	sort(a + l, a + mid + 1, cmpy);
	sort(a + mid + 1, a + r + 1, cmpy);
	p = l;
	rep(i, mid + 1, r + 1){
		while (p <= mid && a[p].y < a[i].y) {
			o = 1;l1 = r1 = a[p].z; ma = a[p].ma;
			change(1, n, 1);
			p++;
		}
		l1 = 1; r1 = a[i].z - 1; ma = 0; 
		if (l1 <= r1) ask(1, n, 1);
		a[i].ma = max(a[i].ma, ma + 1);
	}
	rep(i, l, p) {
		o = 0; l1 = r1 = a[i].z;
		change(1, n, 1);
	}
	sort(a + mid +1, a + r + 1, cmpx);
	CDQ(mid+1, r);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> x >> y;
		a[i] = {i, x, y, 1};
	}
	CDQ(1, n);
	rep(i, 1, n+1) ans = max(ans, a[i].ma);
	cout << ans;
	return 0;
}

