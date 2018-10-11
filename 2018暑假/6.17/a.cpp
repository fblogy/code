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
	int x,y;
}a[100],b[100];

int x,n,s,m,k,num;
bool ok,f[20];


int main(){
	freopen("a.in","r",stdin);
	cin>>n>>m;
	rep(i,0,n) {
		cin>>a[i].x>>a[i].y;
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	rep(i,0,m) {
		cin>>b[i].x>>b[i].y;
		if (b[i].x>b[i].y) swap(b[i].x,b[i].y);
	}
	rep(i,0,n) rep(j,0,m) {
		if (a[i].x==b[j].x&&a[i].y==b[j].y) continue;
		if (a[i].x==b[j].x) {f[a[i].x]=1;}
		if (a[i].x==b[j].y) {f[a[i].x]=1;}
		if (a[i].y==b[j].x) {f[a[i].y]=1;}
		if (a[i].y==b[j].y) {f[a[i].y]=1;}
	}
	int pos;
	rep(i,1,10) if (f[i]) num++,pos=i;
	if (num==1) cout<<pos;else {
		ok=1;
		rep(i,0,n) {
			memset(f,0,sizeof(f));
			rep(j,0,m) {
				if (a[i].x==b[j].x&&a[i].y==b[j].y) continue;
				if (a[i].x==b[j].x||a[i].x==b[j].y) f[a[i].x]=1;
				if (a[i].y==b[j].x||a[i].y==b[j].y) f[a[i].y]=1;
			}
			s=0;rep(k,1,10) if (f[k]) s++;
			if (s>1) ok=0;
		}
		rep(j,0,m) {
			memset(f,0,sizeof(f));
			rep(i,0,n) {
				if (a[i].x==b[j].x&&a[i].y==b[j].y) continue;
				if (a[i].x==b[j].x||a[i].x==b[j].y) f[a[i].x]=1;
				if (a[i].y==b[j].x||a[i].y==b[j].y) f[a[i].y]=1;
			}
			s=0;rep(k,1,10) if (f[k]) s++;
			if (s>1) ok=0;
		}
		if (ok) cout<<0;else cout<<-1;
	}
	return 0;
}

