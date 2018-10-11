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

const int N=60005;
const int mod=1e9+7;

int n;
ll x,num,a[N];
int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	x=1ll*(n+1)*n/2;
	printf("%d\n",x%2);
	x/=2;
	for (int i=n;i>=1;i--) if (x>=i) {
		x-=i;a[++num]=i;
	}
	printf("%d ",num);
	rep(i,1,num+1) printf("%d ",a[i]);
	return 0;
}
