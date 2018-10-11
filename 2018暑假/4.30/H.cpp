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

//using std::bitset;
int n,m;
char s[N],c[N];
bitset<N> a,b;
int main(){
	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,c+1);
	
	rep(i,1,n+1) if (s[i]=='R') a[i]=1;else a[i]=0;
	rep(i,1,m+1) if (c[i]=='P') b[i]=1;else b[i]=0;
	rep(i,1,n+1) ans1[i]=(a[i]&b[i]).count();
	return 0;
}
