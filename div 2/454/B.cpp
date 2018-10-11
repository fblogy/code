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

string s[10][10];

int x,y,px,py,l,r;
bool ok;
int main(){
	freopen("a.in","r",stdin);
	rep(i,0,3) {
		rep(j,0,3) getline(cin,s[i][j]);
		if(i!=2) getchar();
	}
	cin>>x>>y;
	//de(x);de(y);
	px=x%3;if (px==0) px=3;py=y%3;if (py==0) py=3;	
	px--;
	switch (py) {
		case 1:l=0;r=3;break;
		case 2:l=4;r=7;break;
		case 3:l=8;r=11;break;
	}
	rep(i,0,3) rep(j,l,r) {
		if (s[px][i][j]=='.') ok=1; 
	}
	if (ok) {
		rep(i,0,3) rep(j,l,r) {
			if (s[px][i][j]=='.') s[px][i][j]='!'; 
		}
	}else {
		rep(i,0,3) rep(j,0,3) rep(k,0,sz(s[i][j])) {
			if (s[i][j][k]=='.') s[i][j][k]='!';
		}
	}
	rep(i,0,3) {
		rep(j,0,3) cout<<s[i][j]<<endl;
		cout<<endl;
	}
	return 0;
}

