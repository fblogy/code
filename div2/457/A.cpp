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

int h,m,w,ans,x;

int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>x;
	cin>>h>>m;
	w=h*60+m;
	while (1) {
		h=w/60;m=w%60;
		if (h%10==7||w%10==7) break;
		w-=x;ans++;
		if (w<0) w+=24*60;
	}
	cout<<ans;
	return 0;
}

