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

const int N=1005;
const int mod=1e9+7;

int n,m,b[N],c[N];
int a[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

bool check(int p1,int p2,int p3){
	m=0;
	rep(i,0,12) b[++m]=a[p1][i];
	rep(i,0,12) b[++m]=a[p2][i];
	rep(i,0,12) b[++m]=a[p3][i];
	rep(i,1,m+1) if (i+n-1<=m){
		bool ok=1; 
		rep(j,1,n+1) if (b[i+j-1]!=c[j]) {ok=0;break;}
		if (ok) return 1;
	}
	return 0;
}

int main(){
	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&c[i]);
	if (check(0,0,1)||check(0,1,0)||check(1,0,0)||check(0,0,0)) printf("Yes");else printf("No");
	return 0;
}
