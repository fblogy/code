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

const int N=5005;
const int mod=1e9+7;

string s;
int ans,num;
bool f[N][N],g[N][N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	rep(i,0,sz(s)) {
		num=0;
		rep(j,i,sz(s)) {
			if (s[j]==')') num--;else num++;
			if (num>=0) f[i][j]=1;else break;
		}
	}
	for(int i=sz(s)-1;i>=0;i--) {
		num=0;
		for(int j=i;j>=0;j--){
			if (s[j]=='(') num--;else num++;
			if (num>=0) g[j][i]=1;else break;
		}
	}
	rep(i,0,sz(s)) 
		for(int j=i+1;j<sz(s);j+=2) if (f[i][j]&&g[i][j]) ans++;
	cout<<ans;
	return 0;
}

