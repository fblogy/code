#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define rint register int
inline int rf(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}
bitset<100000032> _b; int n; uint A, B, C, D, Ans;
inline uint f(int p){
    return((A*p+B)*p+C)*p+D;
}
inline int cnt(int p, int n){
    int r=0;
    for(;n/=p;r+=n);
    return r;
}
inline auto b(int i)->decltype(_b[0]){
    return _b[(i&1)&&(i%6!=3)?i/6<<1|((i%6)>1):0];
}
inline auto b2(int i)->decltype(_b[0]){
    return _b[i/6<<1|1];
}
inline auto b3(int i)->decltype(_b[0]){
    return _b[i/6<<1];
}

int main()
{
    n = rf();
    A = rf();
    B = rf();
    C = rf();
    D = rf();
    _b[0] = 1;
    Ans = cnt(2,n)*f(2)+cnt(3,n)*f(3);
    for(rint i = 5, j, z, c, w; i <= n; i += 4){
        if(!b2(i))
        {
            Ans += cnt(i,n)*f(i);
            if(i <= 20000){
                w = i + i;
                c = w % 6;
                z = (i * i) % 6;
                if(c == 0){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w){
                            b3(j) = 1;
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w){
                            b2(j) = 1;
                        }
                    }
                }else if(c == 2){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w){
                            b3(j) = 1;
                            j += w + w;
                            if(j <= n){
                                b2(j) = 1;
                            }
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w + w){
                            b2(j) = 1;
                            j += w;
                            if(j <= n){
                                b3(j) = 1;
                            }
                        }
                    }
                }else if(c == 4){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w + w){
                            b3(j) = 1;
                            j += w;
                            if(j <= n){
                                b2(j) = 1;
                            }
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w){
                            b2(j) = 1;
                            j += w + w;
                            if(j <= n){
                                b3(j) = 1;
                            }
                        }
                    }
                }
            }
        }
        i += 2;
        if(i <= n && !b3(i))
        {
            Ans += cnt(i,n)*f(i);
            if(i <= 20000){
                w = i + i;
                c = w % 6;
                z = (i * i) % 6;
                if(c == 0){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w){
                            b3(j) = 1;
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w){
                            b2(j) = 1;
                        }
                    }
                }else if(c == 2){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w){
                            b3(j) = 1;
                            j += w + w;
                            if(j <= n){
                                b2(j) = 1;
                            }
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w + w){
                            b2(j) = 1;
                            j += w;
                            if(j <= n){
                                b3(j) = 1;
                            }
                        }
                    }
                }else if(c == 4){
                    if(z == 1){
                        for(j = i * i; j <= n; j += w + w){
                            b3(j) = 1;
                            j += w;
                            if(j <= n){
                                b2(j) = 1;
                            }
                        }
                    }else if(z == 5){
                        for(j = i * i; j <= n; j += w){
                            b2(j) = 1;
                            j += w + w;
                            if(j <= n){
                                b3(j) = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%u\n",Ans);
    return 0;
}
