// 11320 삼각 무늬 - 1
// https://www.acmicpc.net/problem/11320
#include <stdio.h>

int main(){
    int T, A, B;
    scanf("%d", &T);
    while (T-- > 0){
        scanf("%d %d", &A, &B);
        printf("%d\n", (A / B) * (A / B));
    }
}