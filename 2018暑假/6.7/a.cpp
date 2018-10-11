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

priority_queue<int> q;
int x,a[N],pos,n;

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	pos=n;
	rep(i,1,n+1) {
		bool ok=1;q.push(a[i]);
		while(!q.empty()&&q.top()==pos) {
			if (!ok) printf(" %d",pos);else printf("%d",pos);
			pos--;q.pop();
			ok=0;
		}
		printf("\n");
	}
	return 0;
}
