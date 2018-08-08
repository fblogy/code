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

int n,m,k,ans,num;
string s[N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	rep(i,0,n) cin>>s[i];
	rep(i,0,n) {
		num=0;
		rep(j,0,m) {
			if (s[i][j]=='.') num++;
			else {
				if (num>=k) ans+=num-k+1;
				num=0;
			}
		}
		if (num>=k) ans+=num-k+1;
	}
	rep(j,0,m) {
		num=0;
		rep(i,0,n) {
			if (s[i][j]=='.') num++;
			else {
				if (num>=k) ans+=num-k+1;
				num=0;
			}
		}
		if (num>=k) ans+=num-k+1;
	} 
	if (k==1) cout<<ans/2;else cout<<ans;
	return 0;
}

