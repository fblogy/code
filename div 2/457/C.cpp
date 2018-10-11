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

int n,m,w,num;
bool f[N];
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,2,n+1000){
		if (f[i]==0) {
			if (i>n) {w=i;break;}
			for(int j=i+i;j<=n+1000;j+=i) f[j]=1;
		}
	}
	cout<<w<<" "<<w<<endl;
	rep(i,1,n-1) cout<<i<<" "<<i+1<<" "<<1<<endl;
	cout<<n-1<<" "<<n<<" "<<w-(n-2)<<endl;
	num=n-1;
	rep(i,1,n+1) rep(j,i+2,n+1) {
		if (num==m) return 0;
		cout<<i<<" "<<j<<" "<<w+1<<endl;
		num++;
	}
	return 0;
}

