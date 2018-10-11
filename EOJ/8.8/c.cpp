#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=250005;
const int mod=1e9+7;

int n, m, l[N], r[N], num, ma, p1, p2, sum[N*2];
vi s;
ll ans;
int main(){
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> l[i] >> r[i];
		s.pb(l[i]);s.pb(r[i]);
		ans += r[i] - l[i] + 1;
	}
	sort(all(s));
	num = unique(all(s)) - s.begin();
	//de(num)
	rep(i, 1, n+1) {
		p1 = lower_bound(s.begin(),s.begin()+num,l[i])-s.begin();
		p2 = lower_bound(s.begin(),s.begin()+num,r[i])-s.begin();
		sum[p1]++;sum[p2+1]--;
	}
	
	rep(i, 0 , num+1) {
		if (i > 0)sum[i] = sum[i-1]+sum[i];
		ma=max(ma,sum[i]);
	}
	printf("%d\n%.14f", ma,1.0 * ans / m);
	return 0;
}

