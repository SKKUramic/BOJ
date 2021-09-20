// 4375 1
// https://www.acmicpc.net/problem/4375
#include <stdio.h>

int main(){
	int n, k;
	while (scanf("%d", &n) != EOF){
		k = 0;
        for (int i = 1; i <= n; i++) { // 그래도 n보단 작지 않을까
            k = k * 10 + 1;
            k %= n;
            if (k == 0) {
                printf("%d\n", i);;
                break;
            }
        }
	}
}