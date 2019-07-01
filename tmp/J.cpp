#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9;

int n , m , K;
int V[N];
LL sum[11] , tmp[N];
char str[N];
int S[N] , top;

LL pool[N][11];

/*
    + -> -1
    - -> -2
    * -> -3
    +/ -> -4
    *: -> -5
    -M -> -6
    ( -> 7
    X -> Q + i
*/

int getsum(int id) {
    LL res = 0;
    for (int i = 0 ; i < 11 ; ++ i) {
        res += sum[i] * pool[id][i] % Q;
        res %= Q;
    }
    return res;
}

int multi(int x , int y) {
    int i , j;
    for (i = 0 ; i < 11 ; ++ i) {
        for (j = 0 ; i + j < 11 ; ++ j) {
            pool[m][i + j] += pool[x][i] * pool[y][j] % Q;
            pool[m][i + j] %= Q;
        }
    }
    return m ++;
}
int multiI(int x , int y) {
    for (int i = 0 ; i < 11 ; ++ i) {
        pool[m][i] = pool[x][i] * y % Q;
    }
    return m ++;
}


int subtract(int x , int y) {
    for (int i = 0 ; i < 11 ; ++ i) {
        pool[m][i] = (pool[x][i] + Q - pool[y][i]) % Q;
    }
    return m ++;
}
int add(int x , int y) {
    for (int i = 0 ; i < 11 ; ++ i) {
        pool[m][i] = (pool[x][i] + pool[y][i]) % Q;
    }
    return m ++;
}


void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&V[i]);
        tmp[i] = 1;
    }
    for (j = 0 ; j < 11 ; ++ j) {
        for (i = 0 ; i < n ; ++ i)
            sum[j] += tmp[i] , sum[j] %= Q;
        for (i = 0 ; i < n ; ++ i)
            tmp[i] *= V[i] , tmp[i] %= Q;
    }
    scanf("%s" , str);
    S[0] = -7;
    K = strlen(str); str[K] = ')';
    for (i = 0 ; i <= K ; ++ i) {
        if (str[i] == 'N') {
            S[++ top] = n;
        } else if (str[i] == 'X') {
            pool[m][1] = 1;
            S[++ top] = m + Q;
            m ++;
        } else if (isdigit(str[i])) {
            LL x = 0;
            while (isdigit(str[i]))
                x = x * 10 + str[i] - '0' , x %= Q , ++ i;
            -- i;
            S[++ top] = x;
        } else if (str[i] == '+') {
            if (str[i + 1] == '/') {
                S[++ top] = -4;
                ++ i;
            } else {
                S[++ top] = -1;
            }
        } else if (str[i] == '-') {
            if (i == 0 || (!isalpha(str[i - 1]) && !isdigit(str[i - 1]) && str[i - 1] != ')'))
                S[++ top] = -6;
            else
                S[++ top] = -2;
        } else if (str[i] == '*') {
            if (str[i + 1] == ':') {
                S[++ top] = -5;
                ++ i;
            } else
                S[++ top] = -3;
        } else if (str[i] == '(') {
            S[++ top] = -7;
        } else {
            assert(str[i] == ')');
            while (S[top - 1] != -7) {
                assert(S[top] >= 0);
                if (S[top - 1] <= -4) {
                    // unary
                    if (S[top - 1] == -4) {
                        //assert(S[top] >= Q);
                        top -= 2;
                        if (S[top + 2] < Q)
                            S[top + 1] = S[top + 2];
                        else {
                            S[top + 1] = getsum(S[top + 2] - Q);
                        }
                        ++ top;
                    }
                    else if (S[top - 1] == -5) {
                        //assert(S[top] >= Q);
                        top -= 2;
                        if (S[top + 2] < Q)
                            S[top + 1] = (LL) S[top + 2] * S[top + 2] % Q;
                        else
                            S[top + 1] = Q + multi(S[top + 2] - Q , S[top + 2] - Q);
                        ++ top;
                    }
                    else if (S[top - 1] == -6) {
                        top -= 2;
                        if (S[top + 2] < Q)
                            S[top + 1] = (Q - S[top + 2]) % Q;
                        else {
                            S[top + 1] = Q + subtract(N - 1 , S[top + 2] - Q);
                        }
                        ++ top;
                    }
                } else {
                    //binary
                    if (S[top - 1] == -3) {
                        top -= 3;
                        if (S[top + 1] < Q && S[top + 3] < Q) {
                            S[top + 1] = (LL) S[top + 1] * S[top + 3] % Q;
                        } else if (S[top + 1] >= Q && S[top + 3] < Q) {
                            S[top + 1] = Q + multiI(S[top + 1] - Q , S[top + 3]);
                        } else if (S[top + 1] < Q && S[top + 3] >= Q) {
                            S[top + 1] = Q + multiI(S[top + 3] - Q , S[top + 1]);
                        } else
                            S[top + 1] = Q + multi(S[top + 1] - Q , S[top + 3] - Q);
                    }
                    else if (S[top - 1] == -1) {
                        top -= 3;
                        if (S[top + 1] < Q && S[top + 3] < Q) {
                            S[top + 1] = (S[top + 1] + S[top + 3]) % Q;
                        } else if (S[top + 1] >= Q && S[top + 3] < Q) {
                            pool[S[top + 1] - Q][0] += S[top + 3];
                            pool[S[top + 1] - Q][0] %= Q;
                            S[top + 1] = S[top + 1];
                        } else if (S[top + 1] < Q && S[top + 3] >= Q) {
                            pool[S[top + 3] - Q][0] += S[top + 1];
                            pool[S[top + 3] - Q][0] %= Q;
                            S[top + 1] = S[top + 3];
                        } else
                            S[top + 1] = Q + add(S[top + 1] - Q , S[top + 3] - Q);
                    }
                    else if (S[top - 1] == -2) {
                        top -= 3;
                        if (S[top + 1] < Q && S[top + 3] < Q) {
                            S[top + 1] = (S[top + 1] + Q - S[top + 3]) % Q;
                        } else if (S[top + 1] >= Q && S[top + 3] < Q) {
                            pool[S[top + 1] - Q][0] += Q - S[top + 3];
                            pool[S[top + 1] - Q][0] %= Q;
                            S[top + 1] = S[top + 1];
                        } else if (S[top + 1] < Q && S[top + 3] >= Q) {
                            int p = subtract(N - 1 , S[top + 3] - Q);
                            pool[p][0] += S[top + 1];
                            pool[p][0] %= Q;
                            S[top + 1] = p + Q;
                        } else
                            S[top + 1] = Q + subtract(S[top + 1] - Q , S[top + 3] - Q);
                    }
                    ++ top;
                }
            }
            assert(S[top - 1] == -7);
            S[top - 1] = S[top];
            -- top;
        }
    }
    printf("%d\n" , S[top]);
}

int main() {
    freopen("j.in" , "r" , stdin);
    freopen("j.out" , "w" , stdout);
    work();
    return 0;
}
