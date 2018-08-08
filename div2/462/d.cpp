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

const int N=100005;
const int mod=1e9+7;

ll now,x,a[N],n,k,p;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>p>>k;
	now=p;n=0;
	while (now>=k || now<0) {
		x=now/k;
		now-=x*k;
		if (now<0) now+=k,x--;
		if (now>=k) now-=k,x++;
		x=-x;
		a[n++]=now;
		now=x;
	}
	a[n++]=now;
	cout<<n<<endl;
	rep(i,0,n) cout<<a[i]<<" ";
	return 0;
}

