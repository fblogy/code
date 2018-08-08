#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long dnt;

int n, T, Q[405005];
dnt sum[405005], f[405005], a[405005];

dnt Y( int i, int j )
{
    return f[j] - sum[j] + j * a[j + 1] - (f[i] - sum[i] + i * a[i + 1]);
}

dnt X( int i, int j )
{
    return a[j + 1] - a[i + 1];
}

dnt DP( int i, int j )
{
    return f[j] + (sum[i] - sum[j]) - (i - j) * a[j + 1];
}

inline dnt R()
{
    static char ch;
    register dnt res, T = 1;
    while( ( ch = getchar() ) < '0'  || ch > '9' )if( ch == '-' )T = -1; 
        res = ch - 48;
    while( ( ch = getchar() ) <= '9' && ch >= '0')
        res = res * 10 + ch - 48;
    return res*T;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("baoli.out","w",stdout);
    sum[0] = 0;
    while(~scanf( "%d%d", &n, &T ))
    {
        a[0] = 0, f[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf( "%I64d", &a[i] );
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        int h = 0, t = 0;
        Q[++t] = 0;
        for(int i = 1; i <= n; i++)
        {
            int cur = i - T + 1;
            for(; h + 1 < t && Y(Q[h + 1], Q[h + 2]) <= i * X(Q[h + 1], Q[h + 2]); h++);
            f[i] = DP(i, Q[h + 1]);
            if(cur < T) continue;
            for(; h + 1 < t && Y(Q[t - 1], Q[t]) * X(Q[t], cur) >= X(Q[t - 1], Q[t]) * Y(Q[t], cur); t--);
            Q[++t] = cur;
        }
        printf( "%I64d\n", f[n] );
    }   
    return 0;
}
