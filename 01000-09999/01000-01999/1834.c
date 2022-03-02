// 1834 나머지와 몫이 같은 수
// https://www.acmicpc.net/problem/1834
#include <stdio.h>

int main(){
	unsigned long long N, i, sum = 0;
	scanf("%llu", &N);
	for (int i = 1; i < N; i++){
		sum += (i * N) + i;
	}
	printf("%llu", sum);
}