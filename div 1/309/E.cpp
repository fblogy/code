#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <assert.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int NN = 40005;
const int mod = 1e9+7;

struct Edge{
	int u, v, w;
	int p[NN];
} edge[105];

ll cnt;
int n, m, t, fine, dis[55][55], u, v, w, k;

db f[55][NN], tmp, g[105][NN];

const int MAXN=1<<18;
const double pi=acos(-1);
int N,na,nb,rev[MAXN*2];
struct complex
{
	double re,im;
	complex(double r=0.0,double i=0.0) {re=r,im=i;}
	void print() {printf("%lf %lf\n",re,im);}
} a[MAXN*2],b[MAXN*2],W[2][MAXN*2];

complex operator +(const complex&A,const complex&B) {return complex(A.re+B.re,A.im+B.im);}
complex operator -(const complex&A,const complex&B) {return complex(A.re-B.re,A.im-B.im);}
complex operator *(const complex&A,const complex&B) {return complex(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}

void FFT(complex*a,int f)
{
	complex x,y;
	for (int i=0; i<N; i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1; i<N; i<<=1)
		for (int j=0,t=N/(i<<1); j<N; j+=i<<1)
			for (int k=0,l=0; k<i; k++,l+=t) x=W[f][l]*a[j+k+i],y=a[j+k],a[j+k]=y+x,a[j+k+i]=y-x;
	if (f) for (int i=0; i<N; i++) a[i].re/=N;
}

//int L;

void work()
{
	for (int i=0; i<N; i++)
	{
		int x=i,y=0;
		for (int k=1; k<N; x>>=1,k<<=1) (y<<=1)|=x&1;
		rev[i]=y;
	}
	
	//for (int i=0;i<N;i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<L);
	
	for (int i=0; i<N; i++) W[0][i]=W[1][i]=complex(cos(2*pi*i/N),sin(2*pi*i/N)),W[1][i].im=-W[0][i].im;
}

void init(int l, int r, int pos)
{
	int mid = (l + r) >> 1;
	//na = r - mid;
	for (int i=0; i<na; i++) a[i].re = f[edge[pos].v][mid + 1 + i];
	//nb = min(r - l + 1, t);
	for (int i=0; i<nb; i++) b[i].re = 1.0 * edge[pos].p[nb - i] / 100000;
	//for (N=1; N<na||N<nb; N<<=1); N<<=1;
	//for (N=1; N < na + nb; N<<=1);
}

void doit(int l, int r, int pos)
{
	int mid = (l + r) >> 1;
	init(l, r, pos);
	//work(),
	FFT(a,0),FFT(b,0);
	for (int i=0; i<N; i++) a[i]=a[i]*b[i];
	FFT(a,1);
	rep(i, 0, N) if (i < nb && mid + 1 + (i - nb) >= l) {
		assert(mid + 1 + (i - nb) >= l && mid + 1 + (i - nb) <= mid); 
		g[pos][mid + 1 + (i - nb)] += a[i].re;
	}
	rep(i, 0, N) a[i] = b[i] = {0, 0};
}

void calc(int l, int r) {
	int mid = (l + r) >> 1;
	na = r - mid;nb = min(r - l + 1, t);
	for (N=1; N < na + nb; N<<=1);
	work();
	rep(i, 1, m+1) doit(l, r, i);
}

void solve(int l, int r) {
	int mid = (l + r) >> 1;
	if (l == r) {
		rep(i, 1, m + 1) {
			u = edge[i].u; v = edge[i].v; w = edge[i].w;
			f[u][l] = min(f[u][l], g[i][l] + w);
		}
		return; 
	} 
	solve(mid + 1, r);
	calc(l, r);
	solve(l, mid);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	cin >> n >> m >> t >> fine;
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 1, n+1) dis[i][i] = 0;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		edge[i] = {u, v, w};
		dis[u][v] = min(dis[u][v], w);
		rep(j, 1, t+1) cin >> edge[i].p[j];
	}
	rep(k, 1, n+1) 
		rep(i, 1, n+1) 
			rep(j, 1, n+1) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
	rep(i, 1, n) rep(j, 0, t+1) f[i][j] = 1e9;
	rep(i, 1, n) rep(j, t, 2 * t + 1) f[i][j] = fine + dis[i][n];
	rep(j, t+1, 2 * t + 1) f[n][j] = fine;
	calc(0, t * 2); 
	solve(0, t);
	cout << f[1][0];
	return 0;
}

