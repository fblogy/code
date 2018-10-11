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

double dis(int x,int y,int x2,int y2) {
	return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d%d%d",&n,&n1,&n2);
	rep(i,1,n1+1) scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n2+1) scanf("%d%d",&x2[i],&y2[i]);
	
	return 0;
}
