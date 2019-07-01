#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;
 
#define NMAX 400005
#define INF 1000000006
 
set<int> myset;
set<int>::iterator it;
 
int indx, n,k, v[NMAX], ans;
int v2[NMAX],extra[NMAX], inv[NMAX];
int f[NMAX];
 
inline void upgrade()
{
    if(indx == n + 1)
        return ;
    int myindex = inv[v2[indx]];
    it = myset.lower_bound(myindex);
    if(it != myset.end())
    {
        int rightindex = (*it);
        if(v[rightindex] < v[myindex])
            return ;
    }
    if(it != myset.begin())
    {
        it--;
        int leftindex = (*it);
        if(v[leftindex] > v[myindex])
            return ;
    }
    myset.insert(myindex);
    indx++;
    upgrade();
}
 
inline int binarySearch(int left, int right, int val)
{
    if(left > right)
        return right;
    int midd = (left + right) / 2;
    if(extra[midd] > val)
        return binarySearch(left, midd - 1, val);
    return binarySearch(midd + 1, right, val);
}
 
inline void check(int left, int right)
{
   // printf("Pai am check cu %d %d\n", left, right);
    int ind1 = binarySearch(1, k, v2[left]);
    int ind2 = binarySearch(1, k, v2[right]);
    int small = ind1, big = k - ind2, medium = ind2 - ind1;
    //printf("La care am small = %d big = %d si med = %d\n",ind1,ind2,medium);
    int got1 = medium / 2, got2 = (medium + 1) / 2;
    right = n - right + 1;
    if(right > left && 2 * (right - 1) <= medium)
    {
        ans = min(ans, 2 * right - 1);
     //   printf("%d\n", 2 * right - 1);
        return ;
    }// caz in care folosesc mijlocul si se termina in max
    if(right <= left && 2 * left - 1 <= medium)
    {
        ans = min(ans, 2 * left);
        //printf("%d\n", 2 * left);
        return ;
    }// caz in care folosesc mijloacele si se termina in min
    left -= got1; left = (left <= 0 ? 0 : left);
    right -= got2; right = (right <= 0 ? 0 : right);
    if(medium&1)
    {
        int aux = left;
        left = right;
        right = aux;
        aux = small;
        small = big;
        big = aux;
    }
    if(!left)
    {
       // printf("eram %d cu %d", 2 * (right - 1), small);
        if(2 * (right - 1) <= small)
        {
            ans = min(ans, 2 * right - 1 + medium);
       //     printf("%d\n", 2 * left);
        }
        return ;
    }
    if(!right)
    {
        //printf("pai pai pai %d %d\n", 2 * left - 1, big);
        if(2 * left - 1 <= big)
            ans = min(ans, 2 * left + medium);
        return ;
    }
    if(2 * (right - 1) <= small)
    {
     //   printf("Nope teste\n");
        int newleft = left + right - 1;
        int newbig = big - 1;
        if(2 * (newleft - 1) <= newbig)
            ans = min(ans, medium + 2 * right - 1 + 2 * newleft - 1);
    }
    if(2 * left - 1 <= big)
    {
        int newright = left + right - 1;
        int newsmall = small - 1;
        if(2 * (newright - 1) <= newsmall)
            ans = min(ans, medium + 2 * left + 2 * newright - 1);
    }
   // printf("Ans este %d\n\n", ans);
}
 
//inline void plsErase(int val)
 
inline void Solve()
{
    indx = 1;
    upgrade();
    check(0, indx);
    for(int i = 1; i <= n; i++)
    {
        myset.erase(inv[v2[i]]);
        upgrade();
        check(i, indx);
    }
}
 
inline void Read()
{
    scanf("%d%d",&n,&k);
    assert(1 <= n && n <= 100000);
    assert(1 <= k && k <= 200000);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&v[i]);
        assert(1 <= v[i] && v[i] <= n + k);
        f[v[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        scanf("%d",&extra[i]);
        assert(1 <= extra[i] && extra[i] <= n + k);
        f[extra[i]]++;
    }
    for(int i = 1; i <= n + k; i++)
        assert(f[i] == 1);
}
 
inline void Prep()
{
    sort(extra + 1, extra + k + 1);
    for(int i = 1; i <= n; i++)
    {
        v2[i] = v[i];
        inv[v[i]] = i;
    }
    sort(v2 + 1, v2 + n + 1);
    v2[n + 1] = INF;
    ans = INF;
}
 
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Read();
    Prep();
    Solve();
    printf("%d\n", (ans > k ? -1 : ans));
 
    return 0;
}
