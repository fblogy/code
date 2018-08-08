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

const int N=200005;
const int mod=1e9+7;

int sy,a,b,n,q,p1,p2,x,y;
int s[N],l[N],r[N];
double L,R,ans;

int main(){
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout<<setiosflags(ios::fixed);
	//cout<<setprecision(8);
	scanf("%d%d%d%d",&sy,&a,&b,&n);
	rep(i,1,n+1) scanf("%d%d",&l[i],&r[i]),s[i]=s[i-1]+r[i]-l[i];
	scanf("%d",&q);
	rep(i,1,q+1) {
		scanf("%d%d",&x,&y);ans=0;
		L=x-1.0*y/(y-sy)*(x-a);
		R=x-1.0*y/(y-sy)*(x-b);
		//dd(L);de(R);
		p1=lower_bound(l+1,l+n+1,L)-l;
		p2=upper_bound(r+1,r+n+1,R)-r;
		p2--;
		//dd(p1);de(p2);
		if (p1<=p2) ans+=s[p2]-s[p1-1];
		if (p1-1==p2+1 && p1-1>=1 && p1-1<=n) ans+=R-L;
		else {
			if (p1-1>0 && L>=l[p1-1] && L<=r[p1-1]) ans+=r[p1-1]-L;
			if (p2+1<=n && R>=l[p2+1] && R<=r[p2+1]) ans+=R-l[p2+1];
		}
		ans*=1.0*(y-sy)/y;
		printf("%.8f\n",ans);
	}
	return 0;
}

