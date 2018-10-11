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

int arr[1005];

int main(){
	//freopen("a.in","r",stdin);
	int n,x;
	scanf("%d",&n);
	priority_queue<int> pq;
	rep(i,1,n+1){
		scanf("%d",&x);
		pq.push(x);
	}
	bool flag = 0;
	int sum1 = 0, sum2 = 0;
	while(!pq.empty())
	{
		int ft = pq.top();
		pq.pop();
		if(flag){
			sum2 += ft;
			flag = 0;
		}
		else{
			sum1 += ft;
			flag = 1;
		}
	}
	printf("%d %d\n",sum1,sum2);
	return 0;
}

