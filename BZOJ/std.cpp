#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;
inline const int Get_Int() {
	int num=0,bj=1;
	char x=getchar();
	while(x<'0'||x>'9') {
		if(x=='-')bj=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9') {
		num=num*10+x-'0';
		x=getchar();
	}
	return num*bj;
}
const int maxn=100005;
int n,Len[maxn],Son[maxn];
LL tmp[maxn*5],*f[maxn],*g[maxn],*now=tmp,ans=0;
vector<int> edges[maxn];
void AddEdge(int x,int y) {
	edges[x].push_back(y);
}
void Dfs(int Now,int fa,int depth) {
	Len[Now]=0;
	for(int Next:edges[Now]) {
		if(Next==fa)continue;
		Dfs(Next,Now,depth+1);
		if(Len[Next]>Len[Son[Now]]) {
			Son[Now]=Next;
			Len[Now]=Len[Next]+1;
		}
	}
}
void TreeDp(int Now,int fa) {
	if(Son[Now]) {
		f[Son[Now]]=f[Now]+1;
		g[Son[Now]]=g[Now]-1;
		TreeDp(Son[Now],Now);
	}
	f[Now][0]=1;
	ans+=g[Now][0];
	for(int Next:edges[Now]) {
		if(Next==fa||Next==Son[Now])continue;
		f[Next]=now,now+=(Len[Next]<<1)+2,g[Next]=now,now+=(Len[Next]<<1)+2;
		TreeDp(Next,Now);
		for(int j=0; j<=Len[Next]; j++) {
			if(j)ans+=f[Now][j-1]*g[Next][j];
			ans+=g[Now][j+1]*f[Next][j];
		}
		for(int j=0; j<=Len[Next]; j++) {
			g[Now][j+1]+=f[Now][j+1]*f[Next][j];
			if(j)g[Now][j-1]+=g[Next][j];
			f[Now][j+1]+=f[Next][j];
		}
	}
}
int main() {
	freopen("a.in","r", stdin);
	freopen("std.out","w",stdout);
	n=Get_Int();
	for(int i=1; i<n; i++) {
		int x=Get_Int(),y=Get_Int();
		AddEdge(x,y);
		AddEdge(y,x);
	}
	Len[0]=-1;
	Dfs(1,0,1);
	f[1]=now,now+=(Len[1]<<1)+2,g[1]=now,now+=(Len[1]<<1)+2; //??????,2?!! 
	TreeDp(1,0);
	printf("%lld\n",ans);
	return 0;
}
