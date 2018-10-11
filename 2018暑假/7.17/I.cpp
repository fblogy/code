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

ll a,b,s[N],x[N],y[N];
int n;

ll dis(int i,int j) {
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int main(){
//	freopen("a.in","r",stdin);
	cin>>n;
	rep(i,1,2*n+1) cin>>x[i]>>y[i];
	rep(i,1,2*n+1) 
		rep(j,1,2*n+1) s[i]+=dis(i,j);
	sort(s+1,s+2*n+1);
	for(int i=2*n;i>=2;i-=2) {
		a+=s[i];
		b+=s[i-1];
	}
	cout<<(a-b)/2;
	return 0;
}
