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

const int N=200005;
const int mod=1e9+7;

int n,x,a[N],w[N],num,pre,m,l[N],r[N],l1,r1,ans;
bool f[N];
priority_queue<pii> q;

int main(){
	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",&x);
		if (i!=1&&x!=pre) {
			m++;a[m]=pre;w[m]=num;
			q.push(mp(num,-m));
			num=1;
		}else num++;
		pre=x;
	}
	m++;a[m]=pre;
	q.push(mp(num,-m));
//	de(m);
	rep(i,1,m+1) l[i]=i-1,r[i]=i+1;
	while (!q.empty()) {
		pii tmp=q.top();q.pop();tmp.se=-tmp.se;
		if (f[tmp.se]) continue;
		ans++;f[tmp.se]=1;
		r1=r[tmp.se];l1=l[tmp.se];
		if (r1<=m&&l1>=1&&a[r1]==a[l1]) {
			w[l1]+=w[r1];f[r1]=1;
			q.push(mp(w[l1],-l1));
			r1=r[r1];
		}
		r[l1]=r1;
		l[r1]=l1;
	}
	printf("%d",ans);
	return 0;
}
