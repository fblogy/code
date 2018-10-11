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
//---

const int N=100005;
const int mod=1e9+7;

int n, now, op, x;
ll sum, num;
priority_queue<int> q1, q2;

int main(){
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	scanf("%d", &n);
	now = -1;
	rep(i, 1, n + 1) {
		scanf("%d", &op);
		if (op == 2) printf("%.8f\n", now - 1.0 * sum / num);
		else {
			scanf("%d", &x);
			if (now != -1) q2.push(now);
			now = x;
			num++;
			sum += x;
			while ((!q1.empty() && -q1.top() < 1.0 * sum / num) || (!q2.empty() && q2.top() > 1.0 * sum / num)) {
				while(!q2.empty() && q2.top() > 1.0 * sum / num){
					sum -= q2.top();
					num--;
					q1.push(-q2.top());
					q2.pop();
				}
				while (!q1.empty() && -q1.top() < 1.0 * sum / num) {
					sum += -q1.top();
					num++;
					q2.push(-q1.top());
					q1.pop();
				}
			}
			/*while (!q2.empty() && q2.top() > 1.0 * sum / num) {
				
			}
			/*while (!q1.empty() && -q1.top() < 1.0 * sum / num) {
				sum += -q1.top();
				num++;
				q2.push(-q1.top());
				q1.pop();
			}*/
		}
	}
	return 0;
}

