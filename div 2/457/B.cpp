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

const int N=200005;
const int mod=1e9+7;

int k,num,d,a[N],m,pos,now,x;
ll n;
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;d=100005;
	while (n>0){
		a[++num+d]=n%2;n>>=1;
		if (a[num+d]==1) m++;
	}
	if (m>k) {cout<<"No";return 0;}
	pos=num;now=m;
	//de(pos);de(num);
	while (now!=k) {
		while (a[pos+d]==0) pos--;
		if (k-now>=a[pos+d]){
			x=a[pos+d];
			now+=x;
			a[pos+d]-=x;
			a[pos+d-1]+=x*2;
		}else break;
	}
	rep(i,0,pos+d+1) if (a[i]>0) {pos=i;break;}
	for(int i=pos;i>=0;i--) {
		if (now==k) break;
		a[i]--;
		a[i-1]+=2;
		now++;
	}
	cout<<"Yes\n";
	for(int i=num+d;i>=0;i--) 
		rep(j,0,a[i]) cout<<i-d-1<<" ";
	return 0;
}

