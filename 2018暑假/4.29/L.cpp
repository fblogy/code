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

map<string,int> q;
long  double f[N];
double ans,w;
string s1,s2;
int m,n,p1,p2;

int id(string s){
	if (q.count(s)==1) return q[s];
	q[s]=++m;
	return m;
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+3) f[i]=-100000000;
	f[id("pink")]=0;
	rep(i,1,n+1) {
		s1=s2="";
		cin>>s1>>s2>>w;
		w=log(w);
		p1=id(s1);p2=id(s2);
		//de(f[p1]);de(f[p2]);
		f[p1]=max(f[p1],f[p2]+w);
	}
	de(log(2));
	//de(id("blue"));
	//de(f[id("blue")]);
	if (f[id("blue")]>10) ans=10;
	else ans=exp(f[id("blue")]);
	ans=min(ans,10.0);
	printf("%.9f",ans);
	return 0;
}
