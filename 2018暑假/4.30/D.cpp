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
int book[1000];
int save[1000];
int cal(int x) {
	int sum=0;
	while(x) {
		sum+=(x%10)*(x%10);
		x/=10;
	}
	return sum;
}
void init(){
	for (int i=0;i<999;++i) save[i]=cal(i);
}
int main(){
	//freopen("a.in","r",stdin);
	int num;
	cin>>num;
	init();
//	for (int i=0;i<20;++i) cout<<save[i]<<endl;
	int now;
	if (num>810) now=cal(num);
	else now=num;
	while (book[now]<=1) {
		book[now]++;
		now=cal(now);
		if (now==1) {
			cout<<"HAPPY"<<endl;
			return 0;
		}
	}
	cout<<"UNHAPPY"<<endl;
	return 0;
}
