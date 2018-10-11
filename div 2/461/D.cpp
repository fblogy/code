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

ll ans;
string s;
int n,sum[N];

struct node{
	string s;
	ll a,b;
} a[N];

bool cmp(node a,node b) {
	return a.a*b.b>b.a*a.b;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,0,n) cin>>a[i].s;
	rep(i,0,n) rep(j,0,sz(a[i].s)) if (a[i].s[j]=='s') a[i].a++;else a[i].b++;
	sort(a,a+n,cmp);
	rep(i,0,n) s+=a[i].s;
	for(int i=sz(s)-1;i>=0;i--) sum[i]=sum[i+1]+(s[i]=='h');
	rep(i,0,sz(s)) if (s[i]=='s') ans+=sum[i+1];
	cout<<ans;
	return 0;
}

