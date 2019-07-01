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

const int N=300005;
int cntn,n,q;
int a[N],root[N],cnt[N*40],L[N*40],R[N*40];//*20

void UP(int nid) {
	cnt[nid]=cnt[L[nid]]+cnt[R[nid]];
}

int upd(int nth, int p, int l=1, int r=n) {
	if(p<l||r<p) return nth;
	int nid = ++cntn;
	if(l==r) {
		cnt[nid] = cnt[nth] + 1;
		return nid;
	}
	int m=l+r>>1;
    L[nid] = upd(L[nth], p , l, m);
	R[nid] = upd(R[nth], p , m+1, r);
	UP(nid);
	return nid;
}

int qry(int idl, int idr, int l, int r, int k) {
	if(l == r) return l;
	int m=l+r>>1, res = -1;
	int cntl = cnt[L[idr]] - cnt[L[idl]];
	int cntr = cnt[R[idr]] - cnt[R[idl]];
	if (cntl > k) {
		res = qry(L[idl], L[idr], l, m, k);
		if (res != -1) return res;
	}
	if (cntr > k) {
		res = qry(R[idl], R[idr], m+1, r, k);
		if (res != -1) return res;
	}
	return -1;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> q;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) root[i]=upd(root[i-1], a[i]);
	while(q--) {
		int l,r,k;
		cin >> l >> r >> k;
		cout << qry(root[l-1], root[r], 1, n, (r - l + 1) / k) << endl;
	}
	return 0;
}


