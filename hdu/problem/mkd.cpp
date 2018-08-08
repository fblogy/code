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

int n,t;

int main(){
	freopen("a.in","w",stdout);
	srand(time(0));
	rep(cas,0,10) {
		n=100000;t=rand()%n+1;
		printf("%d %d\n",n,t);
		rep(i,1,n+1) printf("%d ",rand()%100000);
		puts("");
	}
	return 0;
}
