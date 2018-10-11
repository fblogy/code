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

const int N=235;
const int mod=1e9+7;
int low[N],cntp,p[N];
bool isp[N];
 
void getprime() {
	fill_n(isp + 2, N - 2, 1);
	rep(i, 2, N) {
		if (isp[i]) p[cntp++]=i;
		for (int j=0;j<cntp&&p[j]*i<N;j++){
			//low[p[j] * i] = p[j];
			isp[p[j] * i] = 0;
			if (i % p[j] == 0) break;
		}
	}
}

int n, tmp, ma;
bool f[235];
vi q, ans;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	getprime();
	rep(n,130,131) {
	ma = 1 << 30;
	//rep(i, 0, cntp) cout << p[i] << endl;
	//q.pb(2);
	rep(t, 0 , 1<<10) {
		q.clear();
		rep(i, 0 , 10) if (((1<<i) & t)) q.pb(p[i]);
		if (sz(q)>=ma) continue;
		memset(f,0,sizeof(f));
		f[0] = 1;
		rep(i, 0, sz(q))
			for(int j = n; j >= 1; j--) if (j - q[i] >= 0 && f[j - q[i]]) f[j] = 1;
		//de(sz(q));
		tmp = 0;
		rep(i, 0, cntp) if (p[i]<=n && !f[p[i]]) tmp++;
		if (tmp == 0 && sz(q) < ma)  {
			ma = sz(q);
			ans = q;
		}
	}
	rep(z , 1, 120) if (!isp[z]){
	rep(t, 0 , 1<<10) {
		q.clear();q.pb(z);
		rep(i, 0 , 10) if (((1<<i) & t)) q.pb(p[i]);
		if (sz(q)>=ma) continue;
		memset(f,0,sizeof(f));
		f[0] = 1;
		rep(i, 0, sz(q))
			for(int j = n; j >= 1; j--) if (j - q[i] >= 0 && f[j - q[i]]) f[j] = 1;
		//de(sz(q));
		tmp = 0;
		rep(i, 0, cntp) if (p[i]<=n && !f[p[i]]) tmp++;
		if (tmp == 0 && sz(q) < ma)  {
			ma = sz(q);
			ans = q;
		}
	}
	}
	/*rep(z , 30, 50) rep(k, 50, 100) if (!isp[z] && !isp[k]){
	rep(t, 0 , 1<<9) {
		q.clear();q.pb(z);
		rep(i, 0 , 9) if (((1<<i) & t)) q.pb(p[i]);
		if (sz(q)>=ma) continue;
		memset(f,0,sizeof(f));
		f[0] = 1;
		rep(i, 0, sz(q))
			for(int j = n; j >= 1; j--) if (j - q[i] >= 0 && f[j - q[i]]) f[j] = 1;
		//de(sz(q));
		tmp = 0;
		rep(i, 0, cntp) if (p[i]<=n && !f[p[i]]) tmp++;
		if (tmp == 0 && sz(q) < ma)  {
			ma = sz(q);
			ans = q;
		}
	}
	}
	/*if (ma > 8) {
		ma = 8;
		rep(i, 0, ma) ans[i] = 1 << i;
	}*/
	cout <<n <<" "<< ma << endl;
	/*rep(i, 0, ma) {
		cout << ans[i]; 
		if (i != ma-1) cout << " ";
	}*/
	cout<<endl;
	}
	return 0;
}

