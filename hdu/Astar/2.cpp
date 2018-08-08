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

int T,n,m,q,sum[N][26],w,l,r;
string s;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(cas, 0, T) {
		cout<<"Case #"<<cas+1<<":\n";
		cin>>n>>q>>s;
		rep(i,1,n+1) {
			rep(j, 'A', 'Z'+1) {
				sum[i][j-'A']=sum[i-1][j-'A'];
			}
			sum[i][s[i-1]-'A']++;
		}
		rep(i,1,q+1) {
			cin>>l>>r;
			rep(j,'A','Z'+1) {
				w=sum[r][j-'A']-sum[l-1][j-'A'];
				if (w>0) { cout<<w<<endl; break; }
			}
		}
	}
	return 0;
}

