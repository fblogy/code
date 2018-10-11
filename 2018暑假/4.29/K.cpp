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

int n,h[N],l,r,x;
bool f[N],vis[N];
char c[N][N];

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,0,n) scanf("%s",c[i]);
	//de(c[0]);
//	rep(i,0,n) if(!f[i]) {
		memset(vis,0,sizeof(vis));
		l=1;r=1;vis[0]=1;h[l]=0;
		while (l<=r) {
			x=h[l];
			rep(j,0,n) if (j!=x && c[x][j]=='1' && !vis[j]){
				h[++r]=j;vis[j]=1;
			}
			l++;
 		}
 		if (r==n) {
			 for (int i=r;i>=1;i--) printf("%d ",h[i]);
			 return 0;
		}
//	}
	printf("impossible");
	return 0;
}
