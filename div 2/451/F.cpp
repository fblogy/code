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

const int N=1000005;
const int mod=1e9+7;

int n,x,l;
ull w[N],p[N];
ll ww[N],pp[N];
char s[N];

bool solve(int a,int b,int c) {
	if (!((w[b-1]+w[c-1]-w[b-1]*p[c-b])==(w[n-1]-w[c-1]*p[n-c]))) return 0;
	ll x=ww[b-1]+ww[c-1]-ww[b-1]*pp[c-b],y=ww[n-1]-ww[c-1]*pp[n-c];
	x%=mod;y%=mod;
	if (x<0) x+=mod;
	if (y<0) y+=mod;
	return x==y;
}

bool check(int a,int b,int c) {
	if (a>=b||b>=c) return 0;
	if (s[a]=='0') {if (b!=1) return 0;}
	if (s[b]=='0') {if (c!=b+1) return 0;}
	if (s[c]=='0') {if (c!=n-1) return 0;}
	if (solve(a,b,c)){
		rep(i,0,b) printf("%c",s[i]);
		printf("+");
		rep(i,b,c) printf("%c",s[i]);
		printf("=");
		rep(i,c,n) printf("%c",s[i]);
		return 1;
	}else  return 0;
}

int main(){
	freopen("a.txt","r",stdin);
	scanf("%s",s);n=strlen(s);
	w[0]=s[0]-'0';rep(i,1,n) w[i]=w[i-1]*10+s[i]-'0';
	ww[0]=s[0]-'0';rep(i,1,n) ww[i]=ww[i-1]*10+s[i]-'0',ww[i]%=mod;
	p[0]=1;rep(i,1,n+1) p[i]=p[i-1]*10;
	pp[0]=1;rep(i,1,n+1) pp[i]=pp[i-1]*10%mod;
	for (int i=n-1;i>=2;i--) if (s[i]!='0'||i==n-1){
		l=n-i;
		if (check(0,l-1,i)) return 0;
		if (check(0,l,i)) return 0;
		if (check(0,i-(l-1),i)) return 0;
		if (check(0,i-l,i)) return 0;
	}
	return 0;
}
