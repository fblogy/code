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

int T,ans,ansl,ansr,posl,posr,n;
pii pos[N][25];
int dp[N][25],x;
string s,t;

int main(){
	freopen("a.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin>>T;
    //rep(cas,0,T) {
        cin>>n;s=" "+s;ans=0;
        rep(i,1,n+1) cin>>x,s+=x+'0';
		rep(a,1,3)
            rep(b,a,3) {
                t=" ";
                rep(i,0,a+1) t+=i+'0';
                posl=sz(t);
                for(int i=b;i>=a;i--) t+=i+'0';
                posr=sz(t)-1;
                rep(i,b,3) t+=i+'0';
                rep(i,1,sz(s)) rep(j,1,sz(t)) {
                    dp[i][j]=dp[i-1][j]+(s[i]==t[j]);
                    if (dp[i][j]<dp[i][j-1]) {
                        dp[i][j]=dp[i][j-1];
                        pos[i][j]=pos[i][j-1];
                    }else {
                        pos[i][j]=pos[i-1][j];
                        if (j>=posl&&j<=posr) {
                            if (!pos[i][j].fi) pos[i][j].fi=i;
                            pos[i][j].se=i;
                        }
                    }
                }
                int m=sz(t)-1;
                if (dp[n][m]>ans) {
                    ans=dp[n][m];ansl=pos[n][m].fi;ansr=pos[n][m].se;
                }
            }
        if (ansl==0) ansl=ansr=1;
        cout<<ans<<endl;//<<" "<<ansl<<" "<<ansr<<endl;
    //}
    return 0;
}
