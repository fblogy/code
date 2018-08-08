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

const int N=1000005;
const int mod=1e9+7;
ll n,k;
bool vis[N];
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	/*rep(i,1,n) {
		dd(i);de(n%i);
	}*/
	rep(i,1,k+1) {
		if (vis[n%i]) {cout<<"No"<<endl;return 0;}
		vis[n%i]=1;
	}
	cout<<"Yes";
	return 0;
}

