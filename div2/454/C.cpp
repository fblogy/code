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

int f[N],n,ans,num,now;
string op,s;

int main(){
	freopen("a.in","r",stdin);
	cin>>n;now=0;
	rep(cas,1,n) {
		cin>>op>>s;
		if (op[0]=='.') {
			rep(i,0,sz(s)) f[s[i]]=-1;
		}else if (op[0]=='!') {
			rep(i,0,sz(s)) if (f[s[i]]==now) f[s[i]]=cas;now=cas;
			rep(i,'a','z'+1) if (f[i]!=now) f[i]=-1;
		}else if (op[0]=='?') {
			f[s[0]]=-1;
		}
		num=0;rep(i,'a','z'+1) if (f[i]==now) num++;
		if (num==1) {
			rep(i,cas+1,n) {cin>>op>>s;if (op[0]!='.') ans++;}
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}

