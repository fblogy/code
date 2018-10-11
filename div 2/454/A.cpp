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

int a,b,c,d;
bool check(int x,int y){
	return x<=y&&2*x>=y;
}

int main(){
	freopen("a.in","r",stdin);
	cin>>a>>b>>c>>d;
	rep(i,1,201)
		rep(j,1,i)
			rep(k,1,j) {
				if (check(a,i)&&check(b,j)&&check(c,k)&&check(d,k)&&2*d<j&&2*d<i) {
					cout<<i<<endl<<j<<endl<<k;
					return 0;
				} 
			
			}
	cout<<-1;	
	return 0;
}
