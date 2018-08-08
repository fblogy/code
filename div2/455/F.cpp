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

int pos,y,a[N],n;

void work(int n) {
	if (n==0) return;
	for (int i=20;i>=0;i--) if ((1<<i)&n) {pos=i;break;}
	rep(i,(1<<pos),n+1) {
		y=(1<<(pos+1))-1-i;
		a[y]=i;a[i]=y;
	}
	work(y-1);	
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if (n%2==1) cout<<"NO\n";
	else {
		cout<<"YES\n";
		work(n);
		rep(i,1,n+1) cout<<a[i]<<" ";
		cout<<"\n";
	}  
	if (n<=5 || (n&-n)==n) cout<<"NO\n";
	else {
		cout<<"YES\n";
		if (n==6) cout<<"3 6 2 5 1 4";
		else {
			rep(i,3,20) {
				rep(j,1<<i,min((1<<i+1),n+1)) 
					if (j<min((1<<i+1)-1,n)) a[j]=j+1;
					else a[j]=1<<i;
			}
			cout<<"7 3 6 5 1 2 4";
			rep(i,8,n+1) cout<<" "<<a[i];
		}
	}
	return 0;
}

