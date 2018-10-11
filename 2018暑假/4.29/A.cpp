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
const double pi=acos(-1);

int n,m,x,y,x2,y2;
double r,ans1,ans2;

int main(){
	//freopen("a.in","r",stdin);
	scanf("%d%d%lf",&n,&m,&r);
	scanf("%d%d%d%d",&x,&y,&x2,&y2);
	ans1=abs(y-y2)*r/m;ans2=1<<30;
	for (int i=min(y,y2);i>=0;i--) ans2=min(ans2,i*pi*r/m*abs(x-x2)/n+2*r*(min(y,y2)-i)/m);
	printf("%.9f",ans1+ans2);
	return 0;
}
