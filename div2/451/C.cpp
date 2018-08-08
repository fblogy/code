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

const int N=25;
const int mod=1e9+7;

int n,x,id,m,f[N][1000];
string s,s1,b[N];
vector<string> a[N];
map<string,int> q;

bool check(string s1,string s2) {
	if (sz(s1)>sz(s2)) return 0;
	int p1=sz(s1)-1,p2=sz(s2)-1;
	while (p1>=0) {
		if (s1[p1]!=s2[p2]) return 0;
		p1--;p2--;
	}
	return 1;
}

bool cmp(string a,string b) {
	return sz(a)<sz(b);
}

int main(){
	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) {
		s="";
		cin>>s>>x;
		if (q.count(s)==0) id=q[s]=++m,b[m]=s;else id=q[s];
		rep(i,1,x+1) {
			s1="";cin>>s1;
			a[id].pb(s1);
		} 
	}
	printf("%d\n",m);
	rep(i,1,m+1) {
		x=0;
		sort(a[i].begin(),a[i].end(),cmp);
		rep(j,0,sz(a[i])) {
			x++;
			rep(k,j+1,sz(a[i])) if (check(a[i][j],a[i][k])) {f[i][j]=1;x--;break;}
		}
		cout<<b[i]<<" "<<x<<" ";
		rep(j,0,sz(a[i])) if (!f[i][j]) cout<<a[i][j]<<" ";
		puts("");
	}
	return 0;
}
