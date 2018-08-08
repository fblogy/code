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

int sum,num,ans,l[N],r[N],tmp[N*2],x;
string s;
queue<int> q;
bool vis[N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	rep(i,0,sz(s)) l[i]=i-1,r[i]=i+1,q.push(i);
	while (1) {
		num=0;
		while (!q.empty()) {
			x=q.front();
			if ((l[x]>=0 && s[x]!=s[l[x]]) || (r[x]<sz(s) && s[x]!=s[r[x]])) tmp[++num]=x;
			q.pop();
		}
		sum=0;
		rep(i,1,num+1) if (!vis[tmp[i]]) {
			x=tmp[i];vis[x]=1;
			if (l[x]>=0) {r[l[x]]=r[x];q.push(l[x]);}
			if (r[x]<sz(s)) {l[r[x]]=l[x];q.push(r[x]);}
			sum++;
		}
		if (sum>0) ans++;else break;
 	} 
 	cout<<ans;
	return 0;
}

