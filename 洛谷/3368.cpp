#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

template<class T>
struct Fenwick{
    static const int N =5e5+7;
    int n;T a1[N],a2[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,0);fill_n(a1+1,n=_n,0);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p]+=d; }
	void add(int l,int r,T d) {
		add(a1, l, d), add(a1, r + 1, -d);
		add(a2, l, d * (l - 1)), add(a2, r + 1, -d * r);
	} 
	T sum(T *a,int p) { T r=0; for(; p>=1; p-=p & -p) r+=a[p]; return r; }
	T pre(int p) { return !p ? 0 : sum(a1, p) * p - sum(a2, p);}
	T qry(int l,int r) { return pre(r)-pre(l-1); }
};

Fenwick<ll> fen;

int n,m,x,l,r,op,k;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	fen.ini(n);
	rep(i,1,n+1) {
		cin>>x;fen.add(i,i,x);
	}
	rep(i,1,m+1) {
		cin>>op;
		if (op==1) {
			cin>>x>>k;
			fen.add(x,x,k);
		}else {
			cin>>l>>r;
			cout<<fen.qry(l,r)<<endl;
		}
	}
	return 0;
}

