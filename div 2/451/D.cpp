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

const int N=200005;
const int mod=1e9+7;

int n,x,p,a[N],q[N],ans,m,k,l,r;
int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=1;r=0;p=1;
	rep(i,1,1e6+1) {
		while (p<=n&&a[p]<=i+m-1) q[++r]=a[p++];
		while (l<=r && q[l]<i) l++;
		while (r-l+1>=k) r--,ans++; 
	}
	printf("%d",ans);
	return 0;
}
