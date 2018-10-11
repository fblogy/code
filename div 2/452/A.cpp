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

int n,x,ans,num1,num2;
int main(){
	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&x);
		x==1?num1++:num2++;
	}
	ans=min(num1,num2);
	num1-=ans;num2-=ans;
	ans+=num1/3;
	printf("%d",ans);
	return 0;
}
