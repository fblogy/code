#include <stdlib.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <cassert>
 
using namespace std;
 
const int Q=2000000;
const long long R=100000000000000019;
 
char aux[Q];
 
long long lin[Q],col[Q];
 
 
 
long long ax[Q];
 
 
int man[Q];
 
long long prefHash[Q], suffHash[Q];
const int kBase = 398127;
long long Pow[50];
 
void manacher(long long v[], int n)
{ 
    prefHash[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefHash[i] = prefHash[i - 1] * kBase + v[i];
    }
    suffHash[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        suffHash[i] = suffHash[i + 1] * kBase + v[i];
    }
 
    Pow[0] = kBase;
    for(int i = 1; i <= 20; ++i)
        Pow[i] = Pow[i - 1] * Pow[i - 1];
 
    for (int i = 1; i <= n; ++i) {
        man[i + 1] = 0;
        int a = i, b = i + 1, lg = 20;
        for(int step = (1 << 20); step; step /= 2) {
            long long base = Pow[lg--];
            if(a - step + 1 <= 0 || b + step - 1 > n)
                continue;
             
            long long h1 = prefHash[a] - base * prefHash[a - step];
            long long h2 = suffHash[b] - base * suffHash[b + step];
            if(h1 == h2) {
                a -= step;
                b += step;
                man[i + 1] += step;
            }
        }
        assert(lg == -1);
    }
 
    // for (int i = 1; i <= n; ++i) cerr << man[i] << " "; cerr << endl;
}
 
int sp[Q];
 
long long ask(int n,long long v[])
{
 
    memset(sp,0,sizeof sp);
    // memset(man,0,sizeof man);
    // v[n+1]=-1;
 
 
    manacher(v,n);
 
    int last=1;
    sp[1]=1;
 
    for(int i=1; i<=n; i++)
    {
        if(man[i]>0)
        {
            if(last>=i-man[i])
            {
                last=i;
                sp[i]=1;
            }
            else
            {
                sp[i]=0;
            }
        }
        sp[i]+=sp[i-1];
    }
 
    last=n;
 
    long long rez=sp[n];
 
    for(int i=n-1; i>=1; i--)
    {
        if(man[i+1]>0)
        {
            if(last<=i+man[i+1])
            {
                last=i;
                rez+=sp[i];
            }
        }
    }
 
    return rez;
}
 
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
 
    for(int i=1; i<=n; i++)
    {
        fgets(aux+1,Q,stdin);
 
        for(int j=1; j<=m; j++)
        {
            lin[i]=lin[i]*29+aux[j];
            lin[i]%=R;
 
            col[j]=col[j]*29+aux[j];
            col[j]%=R;
        }
    }
 
    long long a,b;
 
    a=ask(n,lin);
    b=ask(m,col);
 
    printf(INT64 "\n",a*b);
 
    return 0;
}
