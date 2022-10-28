#include <stdio.h>

#define I0 11
#define J0 13
#define L0 10

int Min(int x, int y) {
    return x > y ? y : x;
}

int Max(int x,int y) {
    return x > y ? x : y;
}

int Mod(int x,int y) {
    return x * y < 0 ? x - (( x / y ) - 1) * y : x - ( x / y ) * y;
}   

int Abs(int x) {
    return x >= 0 ? x : -x;
}

int NextI(int i , int j, int l, int k) {
    return  Abs(k) - Min(i / 3,Mod(( j + l ),10 )) - 20;
}

int NextJ(int i, int j, int l, int k) {
    return (( - ( j + k )) / 5) + Abs(Mod(( i * l ) , 8));
}

int NextL(int i, int j, int l,int k) {
    return Max(Mod(( i + j ), 15) , Mod(( l + k ), 14));
}

int Checker(int i, int j) {
    if(((i >= 5) && (i <=15)) && ((j <= -5)&&(j >= -15))){
        return 1;
    }
    return 0;
}

int Counter() {
    int iPrev = I0;
    int jPrev = J0;
    int lPrev = L0;
    for (int k = 0; k < 50; ++k) {
    if (Checker(iPrev,jPrev)) {
        return k;
    } else {
        int i = NextI(iPrev, jPrev, lPrev,k);
        int j = NextJ(iPrev, jPrev, lPrev, k);
        int l = NextL(iPrev, jPrev, lPrev,k);
        iPrev = i;
        jPrev = j;
        lPrev = l;
        }
    }
    return 0;
}

int main(void){
    int ans = Counter();
    if (ans == 0) {
        printf("We are not in the square :( \n");
    } else {
        printf("We hit in the square for k = %d \n", ans);
    }
    return 0;
}
