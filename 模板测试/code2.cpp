#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

ll Pow(ll x,ll k,ll p) {
    ll ret=1;
    for (; k; k>>=1,x=x*x%p) if (k&1) ret=ret*x%p;
    return ret; 
}

void ex_gcd(int a,int b,int &x,int &y){
	b ? (ex_gcd(b,a%b,y,x), y-=a/b*x) : x=1,y=0;
}
/*void ex_gcd(int a,int b,int &x,int &y)
{
	if(!b)x=1,y=0;
	else ex_gcd(b,a%b,y,x),y-=a/b*x;
} */ 

inline int Inv(int a,int p) {
	int x, y; ex_gcd(a,p,x,y);
	if (x<0) x+=p; return x;
}

unordered_map<ll, int> M;
ll bsgs(ll y,ll z,ll p){
	if(y%p==0)return -1;
	ll res,sa,now,tmp=1,sq=(ll)(sqrt(p));
	int i,ha;
	M.clear();
	for(i=0;i<=sq;++i){
		if (M.count(tmp)) break; 
		M[tmp] = i;
		tmp=tmp*y%p;
	}
	tmp=p/sq;now=1;sa=Inv(Pow(y,sq,p),p)%p;
	for(i=0;i<=tmp;++i){
		res=now*z%p;
		now=now*sa%p;
		if (M.count(res)) return i*sq+M[res];
	}
	return -1;
}

inline int gcd(int a,int b){
	int tmp;
	while(b!=0)tmp=b,b=a%b,a=tmp;
	return a;
}

//x^y==z(mod p)
ll ex_bsgs(ll y,ll z,ll p) {
	ll t,w=1,ans;int c=0;
	for(t=1,ans=0;ans<=50;++ans){
		if(t==z)return ans;
		t=t*y%p;
	}
	for(t=gcd(y,p); t!=1; t=gcd(y,p)){
		if(z%t)return -1;
		z/=t;p/=t;
		w=w*y/t%p;
		++c;
		if(z==w)return c;
	}
	z=z*Inv(w,p)%p;
	ans=bsgs(y,z,p);
	if(ans==-1)return -1;else return ans+c;
}

ll x,k,z;

int main() {
//    file_put();
    
    while (scanf("%lld%lld%lld",&x,&z,&k)!=EOF && (x || z || k)) {
        ll ans=ex_bsgs(x,k,z);
        if (ans==-1) printf("No Solution\n"); else printf("%lld\n",ans);
    }

//    cout<<ex_bsgs(x,k,z); 
	
	return 0;
}
