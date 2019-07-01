# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <cstring>
# include <cmath>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <map>
# include <set>
# include <deque>
# include <iterator>
# include <functional>
# include <bitset>
# include <climits>
# include <ctime>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define odd(x) ((x)&1)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for (int i=(a); i<=(b); ++i)
#define per(i,a,b) for (int i=(a); i>=(b); --i)
#define rep_it(it,x) for (__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define ____ puts("\n_______________\n\n") 
#define debug(x) ____; cout<< #x << " => " << (x) << endl
#define debug_pair(x) cout<<"\n{ "<<(x).fir<<" , "<<(x).sec<<" }\n"
#define debug_arr(x,n) ____; cout<<#x<<":\n"; rep(i,0,n) cout<<#x<<"["<<(i)<<"] => "<<x[i]<<endl
#define debug_arr2(x,n,m) ____; cout<<#x<<":\n"; rep(i,0,n) rep(j,0,m) cout<<#x<<"["<<(i)<<"]["<<(j)<<"]= "<<x[i][j]<<((j==m)?"\n\n":"    ")
#define debug_set(x) ____; cout<<#x<<": \n"; rep_it(it,x) cout<<(*it)<<" "; cout<<endl
#define debug_map(x) ____; cout<<#x<<": \n"; rep_it(it,x) debug_pair(*it)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int oo = /*2 * 1000 * 1000 * 1000*/0x3f3f3f3f;
const ll ooo=9223372036854775807ll; 
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N=1000005; 
const double PI=acos(-1.0);
const double eps=1e-9;
int o(int x) { return x%_p; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a / gcd(a, b)*b; }

void file_put() {
    string s="/home/jslijin/jslijin/code/";
    freopen((s+"code.in").c_str(), "r", stdin);
    freopen((s+"code.out").c_str(), "w", stdout);
}

const int _N=1e6+5,_M=1e6+5;
template <class V>
struct Tu{
    int head[_N],nxt[_M],e[_M],n,tot; V v[_N],w[_M];
    void Init(int _n) { n=_n; rep(i,1,n) head[i]=0; tot=0; }
    void I(int x,int y,V _w) { e[++tot]=y,w[tot]=_w; nxt[tot]=head[x],head[x]=tot; }
};

struct SPFA{
    int x,cnt[_N]; bool v[_N]; template <class V>
    bool solve(const Tu<V> &T,int s,V dist[],V _oo=oo) {
        queue <int> Q; rep(i,1,T.n) dist[i]=_oo,v[i]=cnt[i]=0;
        dist[s]=0,cnt[s]=1;v[s]=1,Q.push(s);
        while (!Q.empty()) {
            x=Q.front(),Q.pop(),v[x]=0;
            for (int i=T.head[x]; i; i=T.nxt[i])
                if (dist[x]+T.w[i]<dist[T.e[i]]) {
                    dist[T.e[i]]=dist[x]+T.w[i];
                    if (!v[T.e[i]]) {
                        if (cnt[T.e[i]]>= T.n) return 0;
                        Q.push(T.e[i]),v[T.e[i]]=1,cnt[T.e[i]]++;
                    }
                }
        }
        return 1;
    }
};

SPFA S; Tu <int> T; int dist[N],t1,t2; int n,m,l,r,x;

int main() {
   // file_put();
    freopen("a.in","r",stdin);
    int tt, y, z;
	cin >> tt;
    while (scanf("%d%d",&n,&m)!=EOF) {
        T.Init(n);
        rep(i,1,m) {
            scanf("%d%d%d",&x, &y, &z);
            T.I(x, y, z);
	 		if (z >= 0) T.I(y, x, z);
        }
        if (S.solve(T,1,dist,oo)) { puts("N0"); continue; }
        puts("YE5");
    }
    
    return 0;
}
