// 14652 나는 행복합니다
#include <stdio.h>

int main(){
	int m, n, K;
	scanf("%d %d %d", &n, &m, &K);
	printf("%d %d", K / m, K % m);
}