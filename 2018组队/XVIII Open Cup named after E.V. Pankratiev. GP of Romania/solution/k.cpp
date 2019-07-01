#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
 
#define NMAX 805
 
int tris1, tris2, tris3, trisL;
int rest1, rest2, rest3,n,m,nr;
int answer[NMAX][NMAX];
 
void puneL(int px, int py, int dx, int dy) {
    answer[px][py] = ++nr;
    answer[px + dx][py] = nr;
    answer[px][py + dy] = nr;
    n = max(n, px + dx);
    n = max(n, px);
}
 
void puneS1(int px, int py) {
    answer[px][py] = ++nr;
    n = max(n, px);
}
 
void puneS2(int px, int py, int type) {
    answer[px][py] = ++nr;
    if(type){
        answer[px + 1][py] = nr;
            n = max(n, px + 1);
    }
    else {
        answer[px][py + 1] = nr;
        n = max(n, px);
    }
}
 
void puneS3(int px, int py, int type) {
    answer[px][py] = ++nr;
    if(type) {
        answer[px + 1][py] = answer[px + 2][py] = nr;
        n = max(n, px + 2);
    }
    else {
        answer[px][py + 1] = answer[px][py + 2] = nr;
        n = max(n, px);
    }
}
 
int putLs(int line){
    int cLine = line;
    for(int i = 2; i <= trisL; i+= 4) {  //      ** **                     
        puneL(line,2,1,-1);              //       * *            
        puneL(line,4,1, 1);
        line += 4;
    }
    line = cLine + 2;
    for(int i = 4; i <= trisL; i += 4) {  //     ** **            
        puneL(line,1,1,1);                //     *   *     
        puneL(line,5,1,-1);
        line += 4;
    }
    return trisL + cLine;       
}
 
int putS3s(int line, int tris3) {
    for(int i = 2; i <= tris3; i += 2) {  // * *
        puneS3(line, 2, 1);               // * *
        puneS3(line, 4, 1);               // * *
        line += 3;
    }
    return line;
}
 
int putS2s(int line, int tris2) {
    for(int i = 2; i <= tris2; i += 2) {  // * *
        puneS2(line, 2, 1);               // * *
        puneS2(line, 4, 1);
        line += 2;
    }
    return line;
}
 
int putS1s(int line, int tris1) {
    for(int i = 2; i <= tris1; i += 2) {    // * *
        puneS1(line, 2);
        puneS1(line, 4);
        line++;
    }
    return line;
}
 
void transformCase() {
    rest1 = (tris1 & 1);
    rest2 = (tris2 & 1);
    rest3 = (tris3 & 1);
}
 
int main () {
    scanf("%d%d%d%d",&tris1,&tris2,&tris3,&trisL);
    m = 5;
     
    if(trisL % 4 == 3) {
        puneS3(1, 1, 0); tris3--; // 0 orizontal 1 verical
        puneL(1,5,+1,-1); trisL--;  //     11122                    
        puneS1(2,1); tris1--;       //     30002
        int line = putLs(3);
        transformCase();
 
        line = putS3s(line, tris3);
        line = putS2s(line, tris2); 
        line = putS1s(line, tris1); 
         
        if(rest1 && !rest2 && !rest3) { // 1 0 0 
            puneS1(line - 1, 3);
        }
        else if(!rest1 && !rest2 && rest3) { // 0 0 1
            puneS3(line, 2, 0);
        }
        else if(rest1 && rest2 && !rest3) { // 1 1 0
            puneS2(line,2,0);
            puneS1(line,4);
        }
        else { // 0 1 1
            nr--;
            puneS3(line - 1, 4, 1);
            puneS2(line, 2, 1);
            puneS1(line + 1, 3);
        }
    }
    else if(trisL % 4 == 2) {
        int line = 1;
        transformCase();
        if(!rest1 && !rest2 && !rest3) {
            puneS3(1,1,0); tris3--;
            puneS1(1,4); tris1 -= 2;
            puneS1(1,5);
            puneS2(2,1,1); tris2 -= 2;
            puneS2(2,5,1);
            line += 3;
        }
        else if(!rest1 && rest2 && !rest3) {
            puneS3(1,1,0); tris3--;
            puneS2(1,4,0); tris2--;
            puneS1(2,1); tris1 -= 2;
            puneS1(2,5);
            line += 2;
        }
        else if(rest1 && !rest2 && rest3) {
            puneS2(1,1,0);
            puneS1(1,3); tris1--;
            puneS2(1,4,0); tris2 -= 2;
            puneS3(2,1,1); tris3 -= 2;
            puneS3(2,5,1);
            line += 4;
        }
        else {
            puneS2(1,1,0); tris2 -= 3;
            puneS1(1,3);
            puneS2(1,4,0);
            puneS2(2,1,1);
            puneS1(2,5); tris1 -= 3;
            puneS1(3,5);
            line += 3;
        }
 
        //printf("a intrat %d", line);
        line = putLs(line);
        //printf("a iesit %d\n", line);
        line = putS3s(line, tris3);
        line = putS2s(line, tris2); 
        line = putS1s(line, tris1); 
        puneS3(line, 2, 0);
    }
    else if(trisL % 4 == 1) {
        transformCase();
        if(!rest1 && !rest2 && rest3){
            puneS1(1,5);
            puneS1(2,5); tris1 -= 2;
        }
        else {
            puneS2(1,5,1);
            tris2--;
        }
        puneS3(1,2,0); tris3 -= 2;
        puneS3(2,2,1);
        puneL(3,4,1,1); trisL -= 3;
        puneL(5,1,1,1);
        puneL(5,5,1,-1);
        int line = putLs(7);
        line = putS3s(line, tris3);
        line = putS2s(line, tris2); 
        line = putS1s(line, tris1); 
        if(rest1 && !rest2 && !rest3) {
            puneS2(line,2,0);
            puneS1(line,4);
        }
        else if(rest1 && rest2 && !rest3) {
            puneS1(line - 1, 3);
        }
        else {
            puneS3(line, 2, 0);
        }
    }
    else if(trisL % 4 == 0) {
        puneL(1, 1, 1, 1);
        puneL(1, 5, 1,-1);
        trisL -= 2;
        int line = putLs(3);
        transformCase();
         
        line = putS2s(line, tris2); 
         
        if(!rest1 && !rest2 && !rest3) {
            line = putS3s(line, tris3); 
            line = putS1s(line, tris1 - 2); 
             
            puneS1(1,3);
            puneS1(line - 1, 3);
        }
        else if(!rest1 && rest2 && !rest3){
            line = putS3s(line, tris3 - 2); 
            line = putS1s(line, tris1 - 2); 
             
            puneS2(line,2,1);
            puneS1(line + 2, 2);
            puneS3(line,4,1);
            puneS1(1,3);
            puneS3(line + 3, 2, 0);
        } 
        else if(rest1 && !rest2 && rest3) {
            line = putS3s(line, tris3); 
            line = putS1s(line, tris1); 
             
            puneS1(1,3);
            puneS3(line,2,0);
        }
        else {
            line = putS3s(line, tris3); 
            line = putS1s(line, tris1 - 2); 
 
            puneS2(line,2,1);
            puneS1(line + 2, 2);
            puneS3(line,4,1);
            puneS1(1,3);
            puneS1(line + 2, 3);
        }
    }
 
    printf("%d %d\n",n,m);      
    for(int i = 1; i <= n; i++, printf("\n"))
        for(int j = 1; j <= m; j++)
            printf("%d ", answer[i][j]);
     
    return 0;
}
