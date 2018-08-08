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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int f[N],n,ans,num,now,m;
vector<int> a[N];
bool ok;

bool check(){
	if (n<=2&&m<=3) return 0;
	return 1;
}

int main(){
	freopen("a.in","r",stdin);
	cin>>n>>m;
	if (n==1&&m==1) {cout<<"YES\n1";return 0;}
	if (n<=m) rep(i,1,n+1) rep(j,1,m+1) a[i].pb((i-1)*m+j);
	else {
		ok=1;swap(n,m);
		rep(j,1,m+1) rep(i,1,n+1) a[i].pb((j-1)*n+i);
	}
	if (check()) cout<<"YES"<<endl;else {
		cout<<"NO";return 0;
	}
	if (m==4) {
		rep(i,1,n+1) {
			if (i&1) {
				swap(a[i][0],a[i][2]);
				swap(a[i][0],a[i][1]);
				swap(a[i][1],a[i][3]);
			}else {
				swap(a[i][0],a[i][1]);
				swap(a[i][0],a[i][2]);
				swap(a[i][2],a[i][3]);
			}
		}
		if (!ok) {
			rep(i,1,n+1) rep(j,0,m) cout<<a[i][j]<<(j==m-1?"\n":" ");
		}else {
			rep(j,0,m) rep(i,1,n+1) cout<<a[i][j]<<(i==n?"\n":" ");
		}
	}else if (n==3&&m==3) {
		cout<<"6 1 8\n7 5 3\n2 9 4";
	}else {
		rep(i,1,n+1) {
			vector<int> tmp;
			if (i&1) {
				for(int j=1;j<sz(a[i]);j+=2) tmp.pb(a[i][j]);
				for(int j=0;j<sz(a[i]);j+=2) tmp.pb(a[i][j]);
				a[i]=tmp;
			}else {
				for(int j=0;j<sz(a[i]);j+=2) tmp.pb(a[i][j]);
				for(int j=1;j<sz(a[i]);j+=2) tmp.pb(a[i][j]);
				a[i]=tmp;
			}
		}
		if (!ok) {
			rep(i,1,n+1) rep(j,0,m) cout<<a[i][j]<<(j==m-1?"\n":" ");
		}else {
			rep(j,0,m) rep(i,1,n+1) cout<<a[i][j]<<(i==n?"\n":" ");
		}
	}
	return 0;
}

