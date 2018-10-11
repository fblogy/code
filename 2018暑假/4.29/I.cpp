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
int n,m,w,ans ;

int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	if (n%2==1 && m%2==0) {
		if (m>n)ans=2;
		else  ans=0;
	}
	else  if (n%2==1 && m%2==1) ans=1;
	else  ans=0;
	printf("%d",ans);
	return 0;
}
