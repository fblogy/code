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

struct node{
	int d,t;
}a[N];

priority_queue<int> q;
int ans,n,c,now;

bool cmp(node a,node b){
	return a.d<b.d;
}

int main(){
//	freopen("a.in","r",stdin);
	cin>>n>>c;
	rep(i,1,n+1) {
		cin>>a[i].d>>a[i].t;
		a[i].d=c-max(a[i].d,a[i].t)+a[i].t;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n+1) {
		if (now+a[i].t<=a[i].d) {
			ans++;q.push(a[i].t);now+=a[i].t;
		}else {
			if (!q.empty()&&q.top()>a[i].t){
				now-=q.top();now+=a[i].t;
				q.pop();q.push(a[i].t);
			}
		}
	}
	cout<<ans<<" ";
	return 0;
}

