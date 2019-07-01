#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=524288,M=200010,K=18,P=998244353,G=3;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef uint32 word;
typedef uint64 dword;
typedef int sword;
const int word_bits=sizeof(word)*8;
word mod,Modinv,r2;
struct UnsafeMod{
  word x;
  UnsafeMod(): x(0) {}
  UnsafeMod(word _x): x(init(_x)) {}
  UnsafeMod& operator += (const UnsafeMod& rhs) {
    (x += rhs.x) >= mod && (x -= mod);
    return *this;
  }
  UnsafeMod& operator -= (const UnsafeMod& rhs) {
    sword(x -= rhs.x) < 0 && (x += mod);
    return *this;
  }
  UnsafeMod& operator *= (const UnsafeMod& rhs) {
    x = reduce(dword(x) * rhs.x);
    return *this;
  }
  UnsafeMod operator + (const UnsafeMod &rhs) const {
    return UnsafeMod(*this) += rhs;
  }
  UnsafeMod operator - (const UnsafeMod &rhs) const {
    return UnsafeMod(*this) -= rhs;
  }
  UnsafeMod operator * (const UnsafeMod &rhs) const {
    return UnsafeMod(*this) *= rhs;
  }
  UnsafeMod pow(uint64 e) const {
    UnsafeMod ret(1);
    for (UnsafeMod base = *this; e; e >>= 1, base *= base) {
      if (e & 1) ret *= base;
    }
    return ret;
  }
  word get() const {
    return reduce(x);
  }
  static word modulus() {
    return mod;
  }
  static word init(word w) {
    return reduce(dword(w) * r2);
  }
  static void set_mod(word m) {
    mod = m;
    Modinv = mul_inv(mod);
    r2 = -dword(mod) % mod;
  }
  static word reduce(dword x) {
    word y = word(x >> word_bits) - word((dword(word(x) * Modinv) * mod) >> word_bits);
    return sword(y) < 0 ? y + mod : y;
  }
  static word mul_inv(word n, int e = 6, word x = 1) {
    return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }
};
int Case,n,i,j,lim[M];
UnsafeMod a[M],b[M],c[M],d[M];
UnsafeMod ta[N+5],tb[N+5];
UnsafeMod g[K+1],ng[K+10],gw[N+10],ngw[N+10];
int pos[N+10],inv[N+10];
UnsafeMod fac[N+5],rev[N+5];
map<int,UnsafeMod>f[M];
struct E{int xl,xr,yl,yr;}e[M];
inline UnsafeMod C(int n,int m){return n<m?0:fac[n]*rev[m]*rev[n-m];}
inline void NTT(UnsafeMod*a,int n,int t){
  int j=__builtin_ctz(n)-1;
  for(int i=0;i<n;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
  for(int i=1;i<n;i++)if(i<pos[i])std::swap(a[i],a[pos[i]]);
  for(int d=0;(1<<d)<n;d++){
    int m=1<<d,m2=m<<1;
    UnsafeMod*_w=t==1?gw:ngw;
    _w+=m;
    for(int i=0;i<n;i+=m2){
      UnsafeMod*w=_w;
      for(int j=i;j<m+i;j++,w++){
        UnsafeMod t=*w*a[j+m];
        a[j+m]=a[j]-t;
        a[j]+=t;
      }
    }
  }
  if(t==-1){
    UnsafeMod j=inv[n];
    for(int i=0;i<n;i++)a[i]*=j;
  }
}
void build(int l,int r,int yl){
  if(l>r)return;
  int mid=(l+r)>>1;
  e[mid].xl=mid;
  e[mid].xr=r;
  e[mid].yl=yl;
  e[mid].yr=lim[mid];
  build(l,mid-1,yl);
  build(mid+1,r,lim[mid]+1);
}
inline UnsafeMod cal(int x,int y){
  UnsafeMod t=0;
  if(x>1)t=f[x-1][y];
  if(y>1)t+=f[x][y-1];
  return f[x][y]=t;
}
inline void work0(int n,int m,UnsafeMod*a,UnsafeMod*b){
/*
b[i]
=sum_{j=0}^i a[j]*C(i-j+m,m)
=sum_{j=0}^i a[j]*rev[m]*fac[i-j+m]*rev[i-j]
*/
  int i,k;
  /*for(i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      b[i]+=a[j]*C(i+m-j,m);
    }
  }
  return;
  */
  for(k=1;k<=(n-1)*2;k<<=1);
  for(i=0;i<k;i++)ta[i]=tb[i]=0;
  for(i=0;i<n;i++){
    ta[i]=a[i]*rev[m];
    tb[i]=fac[i+m]*rev[i];
  }
  NTT(ta,k,1),NTT(tb,k,1);
  for(i=0;i<k;i++)ta[i]*=tb[i];
  NTT(ta,k,-1);
  for(i=0;i<n;i++)b[i]+=ta[i];
}
inline void work1(int n,int m,UnsafeMod*a,UnsafeMod*b){
/*
b[i]
=sum_{j=0}^{n-1} a[j]*C(i+n-j,i)

fac[n+m-1]

i<=m-1
k<=n+m-1
k=i+n
c[k]
k [n,n+m-1]
=sum_{j=0}^{k} a[j]*C(k-j,k-n)
=rev[k-n]*sum_{j=0}^{k} a[j]*rev[n-j]*fac[k-j]
*/
  int i,k;
  /*for(i=0;i<m;i++){
    for(int j=0;j<n;j++){
      b[i]+=a[j]*C(i+n-j,i);
    }
  }
  return;
  */
  for(k=1;k<=n+n+m-2;k<<=1);
  for(i=0;i<k;i++)ta[i]=tb[i]=0;
  for(i=0;i<n;i++)ta[i]=a[i]*rev[n-i];
  for(i=0;i<n+m;i++)tb[i]=fac[i];
  NTT(ta,k,1),NTT(tb,k,1);
  for(i=0;i<k;i++)ta[i]*=tb[i];
  NTT(ta,k,-1);
  for(i=0;i<m;i++)b[i]+=ta[i+n]*rev[i];
}
inline void solve(int o){
  int xl=e[o].xl,xr=e[o].xr,yl=e[o].yl,yr=e[o].yr;
  if(yl>yr)return;
  int i,j,k,ca,cb;
  if(xl==1){
    for(i=xl;i<=xr;i++)for(j=yl;j<=yr;j++)f[i][j]=C(i+j-2,i-1);
    return;
  }
  cal(xl,yl);
  for(i=yl+1,k=0;i<=yr;i++,k++)a[k]=cal(xl,i);
  for(i=xl+1,k=0;i<=xr;i++,k++)b[k]=cal(i,yl);
  ca=yr-yl-1;
  cb=xr-xl-1;
  if(ca<=0||cb<=0){
    for(i=xl;i<=xr;i++)for(j=yl;j<=yr;j++){
      if(i==xl||j==yl)continue;
      cal(i,j);
    }
    return;
  }
  for(i=0;i<ca;i++)c[i]=b[cb];
  for(i=0;i<cb;i++)d[i]=a[ca];
  work0(ca,cb,a,c);
  work0(cb,ca,b,d);
  work1(ca,cb,a,d);
  work1(cb,ca,b,c);
  for(i=0;i<ca;i++)f[xr][yl+i+1]=c[i];
  for(i=0;i<cb;i++)f[xl+i+1][yr]=d[i];
  f[xr][yr]=c[ca-1]+d[cb-1];
}
int main(){
	freopen("a.in","r",stdin);
  UnsafeMod::set_mod(P);
  for(g[K]=((UnsafeMod)G).pow((P-1)/N),ng[K]=g[K].pow(P-2),i=K-1;~i;i--)g[i]=g[i+1]*g[i+1],ng[i]=ng[i+1]*ng[i+1];
  for(i=0;i<=K;i++){
    gw[1<<i]=ngw[1<<i]=1;
    for(j=1;j<1<<i;j++){
      gw[(1<<i)+j]=gw[(1<<i)+j-1]*g[i];
      ngw[(1<<i)+j]=ngw[(1<<i)+j-1]*ng[i];
    }
  }
  for(inv[0]=inv[1]=1,i=2;i<=N;i++)inv[i]=1LL*(P-inv[P%i])*(P/i)%P;
  for(rev[0]=rev[1]=1,i=2;i<=N;i++)rev[i]=rev[i-1]*inv[i];
  for(fac[0]=i=1;i<=N;i++)fac[i]=fac[i-1]*i;
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&lim[i]);
    n++;
    lim[n]=lim[n-1];
    for(i=1;i<=n;i++)f[i].clear();
    build(1,n,1);
    for(i=1;i<=n;i++)solve(i);
    printf("%u\n",f[n][lim[n]].get());
  }
}
