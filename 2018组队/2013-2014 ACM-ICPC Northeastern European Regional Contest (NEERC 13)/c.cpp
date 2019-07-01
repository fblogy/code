#include<cstdio>
#include<algorithm>
typedef unsigned long long u64;
const int N=500007;
int n,m,fac[N];
int es[N],enx[N],e0[N],e1[N],ep=2;
bool _c[N];
void ae(int*e,int a,int b){
    es[ep]=b;enx[ep]=e[a];e[a]=ep++;
    es[ep]=a;enx[ep]=e[b];e[b]=ep++;
}
void de(int*e,int a,int b){
    for(int*i=e+a;*i;i=enx+*i){
        int u=es[*i];
        if(u==b){
            *i=enx[*i];
            return;
        }
    }
}
int dfn[N],low[N],tk=0,ss[N],sp=0,n1;
void tj(int w,int pa){
    dfn[w]=low[w]=++tk;
    ss[++sp]=w;
    for(int i=e0[w];i;i=enx[i]){
        int u=es[i];
        if(!u)continue;
        if(!dfn[u]){
            es[i^1]=0;
            tj(u,w);
            es[i^1]=w;
            if(ss[sp]==u)--sp,ae(e1,w,u);
        }else if(dfn[u]<dfn[w]){
            int rp=0;
            ae(e1,u,++n1);
            _c[n1]=1;
            while(sp&&dfn[ss[sp]]>dfn[u])ae(e1,ss[sp--],n1);
        }
    }
}
int sz[N],cg[3],cgp=0,rt;
void f1(int w,int pa){
    bool is=1;
    sz[w]=1;
    for(int i=e1[w];i;i=enx[i]){
        int u=es[i];
        if(u==pa)continue;
        f1(u,w);
        sz[w]+=sz[u];
        if(sz[u]*2>n1)is=0;
    }
    if(sz[w]*2<n1)is=0;
    if(is)cg[cgp++]=w;
}
u64 h[N],h1[N],h2[N];
int cs[N],cp;
bool cmp_h(int a,int b){return h[a]<h[b];}
int a1[N],a2[N],mx=2;
u64 a3[N];
void mul(int x){
    ++a1[x];
    if(x>mx)mx=x;
}
void mulfac(int x){
    ++a2[x];
    if(x>mx)mx=x;
}
void f2(int w,int pa){
    for(int i=e1[w];i;i=enx[i]){
        int u=es[i];
        if(u!=pa)f2(u,w);
    }
    cp=0;
    for(int i=e1[w],d=0;i;i=enx[i]){
        int u=es[i];
        if(u==pa){
            d=1;
            continue;
        }
        if(d)cs[cp++]=u;
    }
    for(int i=e1[w];i;i=enx[i]){
        int u=es[i];
        if(u==pa)break;
        cs[cp++]=u;
    }
    if(_c[w]){
        if(w==rt){
            u64 p0=29399999,pp=1;
            for(int i=1;i<=cp;++i){
                h1[i]=h1[i+cp]=h2[i]=h2[i+cp]=h[cs[i-1]];
                pp*=p0;
            }
            for(int i=1;i<=cp*2;++i)h1[i]+=h1[i-1]*p0;
            for(int i=cp*2;i;--i)h2[i]+=h2[i+1]*p0;
            int c=0;
            for(int i=cp;i<cp*2;++i)c+=(h1[i]-h1[i-cp]*pp==h1[cp]);
            for(int i=cp;i;--i)c+=(h2[i]-h2[i+cp]*pp==h1[cp]);
            mul(c);
        }else{
            u64 h1=0,h2=0;
            for(int i=0;i<cp;++i)h1=h1*1399913+h[cs[i]];
            for(int i=cp-1;i>=0;--i)h2=h2*1399913+h[cs[i]];
            if(h1==h2)mul(2);
            h[w]=std::min(h1,h2);
            h[w]^=h[w]>>13^h[w]*17<<31^41546541735416351llu;
        }
    }else{
        std::sort(cs,cs+cp,cmp_h);
        h[w]=0;
        for(int i=0,j=0;i<cp;i=j){
            for(;j<cp&&h[cs[i]]==h[cs[j]];++j);
            mulfac(j-i);
        }
        for(int i=0;i<cp;++i)h[w]=h[w]*1844677+h[cs[i]];
        h[w]^=h[w]>>17^h[w]*11<<23^12218653252112541llu;
    }
}
int _(){
    int x=0,c=getchar();
    while(c<48)c=getchar();
    while(c>47)x=x*10+c-48,c=getchar();
    return x;
}
int ps[N],pp,mp[N],ed[N];
bool np[N];
int main(){
    n=_();m=_();
    n1=n;
    for(int i=0;i<m;++i){
        pp=_();
        for(int j=0;j<pp;++j)ps[j]=_();
        for(int j=0;j<pp-1;++j)ae(e0,ps[j],ps[j+1]);
    }
    for(int w=1;w<=n;++w){
        for(int i=e0[w];i;i=enx[i]){
            int u=es[i];
            if(ed[u]!=w)ed[u]=w;
            else if(u>w)--a1[2];
        }
    }
    tj(1,0);
    f1(1,0);
    if(cgp==2){
        if(_c[cg[0]])rt=cg[0];
        else if(_c[cg[1]])rt=cg[1];
        else{
            rt=++n1;
            ae(e1,n1,cg[0]);
            ae(e1,n1,cg[1]);
            de(e1,cg[0],cg[1]);
            de(e1,cg[1],cg[0]);
        }
    }else rt=cg[0];
    f1(rt,0);
    f2(rt,0);
    for(int i=mx;i;--i)a2[i]+=a2[i+1];
    for(int i=mx;i;--i)a2[i]+=a1[i];
    pp=0;
    for(int i=2;i<=mx;++i){
        if(!np[i])ps[pp++]=mp[i]=i;
        for(int j=0;j<pp&&i*ps[j]<=mx;++j){
            np[i*ps[j]]=1;
            mp[i*ps[j]]=ps[j];
            if(i%ps[j]==0)break;
        }
    }
    for(int i=2;i<=mx;++i){
        for(int x=i;x>1;x/=mp[x])a3[mp[x]]+=a2[i];
    }
    pp=0;
    for(int i=2;i<=mx;++i)if(a3[i])ps[pp++]=i;
    printf("%d\n",pp);
    for(int j=0;j<pp;++j)printf("%d %lld\n",ps[j],a3[ps[j]]);
    return 0;
}
