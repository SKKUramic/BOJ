// 10833 사과
// https://www.acmicpc.net/problem/10833
#include <stdio.h>

int main(){
	int N, sum = 0, a, b;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d %d", &a, &b);
		sum += b % a;
	}
	printf("%d", sum);
}