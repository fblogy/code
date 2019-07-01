#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 33333
int T,n,l[SZ];
ld ar[SZ];
const ld PI=acos(-1);
ld solve_poly(vector<int> S) {
	int a=0,b=int(S.size());
	assert(b > a);
	int sum = 0;
	int hi = S[a];
	vector<int> vals;
	for (int i = a+1; i < b; i++) {
		int cur = S[i];
		if (cur > hi) swap(cur, hi);
		sum += cur;
		vals.push_back(cur);
	}

	if (sum <= hi) {
		return 0;
	}
	auto getAngle = [&](ld D) -> ld{
		ld tot = 0;
		for (int l : vals) {
			tot += 2 * asin(ld(l) / ld(D));
		}
		return tot;
	};

	bool isReflex = (getAngle(hi) < PI);
	auto tooSmall = [&](ld D) {
		ld ang = getAngle(D);
		ld hiAng = 2 * asin(ld(hi) / ld(D));
		if (isReflex) {
			return ang < hiAng;
		} else {
			return ang + hiAng >= 2 * PI;
		}
	};

	ld mi = hi;
	ld ma = hi + 1;
	int numExpand = 0;
	while (tooSmall(ma)) {
		numExpand++;
		ma += (ma - mi);
	}
	for (int i = 0; i < 30 + numExpand; i++) {
		ld md = mi + (ma - mi) / 2;
		if (tooSmall(md)) {
			mi = md;
		} else {
			ma = md;
		}
	}

	ld D = mi;
	ld area = 0;
	for (int l : vals) {
		area += ld(l) * sqrt(ld(D) * ld(D) - ld(l) * ld(l)) / 4;
	}
	ld hiArea = ld(hi) * sqrt(ld(D) * ld(D) - ld(hi) * ld(hi)) / 4;
	if (isReflex) area -= hiArea;
	else area += hiArea;

	return area;
}
pair<ld,int> mx[SZ];
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",l+i);
	random_shuffle(l,l+n);
	for(int i=0;i<(1<<n);++i) ar[i]=0;
	for(int i=0;i<(1<<n);++i)
		if(__builtin_popcount(i)>=3)
		{
			vector<int> v;
			for(int j=0;j<n;++j)
				if(i&(1<<j)) v.pb(l[j]);
			ld w=solve_poly(v);
			if(fabs(w)<=1e-8) continue;
			ar[i]=w;
		}
	for(int i=0;i<(1<<n);++i) mx[i]=mp(0,0);
	for(int i=0;i<(1<<n);++i)
	{
		if(ar[i]) mx[i]=mp(ar[i],-i);
		for(int j=i;j;j=(j-1)&i)
			mx[i]=max(mx[i],mp(mx[i^j].fi*ar[j],-j));
	}
	pair<ld,int> mxx(-8e18,0);
	for(int i=0;i<(1<<n);++i)
		mxx=max(mxx,mp(mx[i].fi,i));
	printf("%.10lf\n",mxx.fi);
	int g=mxx.se;
	vector<int> vs;
	while(1)
	{
		int w=-mx[g].se;
		if(!w) break;
		vs.pb(w); g^=w;
	}
	printf("%d\n",int(vs.size()));
	for(auto r:vs)
	{
		printf("%d",__builtin_popcount(r));
		for(int j=0;j<n;++j)
			if(r&(1<<j)) printf(" %d",l[j]);
		puts("");
	}
}
int main()
{
	freopen("a.in","r",stdin);
	scanf("%d",&T);
	while(T--) sol();
}
