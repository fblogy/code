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

int n;
ll a,b;

int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d%lld%lld",&n,&a,&b);
	rep(i,0,n+1) {
		if (n-i*a<0) break;
		if ((n-i*a)%b==0) {
			printf("YES\n%d %d",i,(n-i*a)/b);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
