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

int w[]={1,1,-1,-1};
int ma[5];
int x,y,d,n,o,a;
int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	d=1;
	rep(i,1,n+1) {
		scanf("%d%d",&a,&o);
		if (d==1||d==3) {printf("%d ",abs(ma[d]-x)+1);x=ma[d]+w[d];ma[d]=x;} 
		if (d==2||d==0) {printf("%d ",abs(ma[d]-y)+1);y=ma[d]+w[d];ma[d]=y;}
		if (o==1) d--;else d++;
		d=(d+4)%4;
	}
	return 0;
}
