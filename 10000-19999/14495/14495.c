// 14495 피보나치 비스무리한 수열
// https://www.acmicpc.net/problem/14495
#include <stdio.h>

long long pibonacci[120];

int main(){
	pibonacci[0] = 0;
	pibonacci[1] = 1;
	pibonacci[2] = 1;
	pibonacci[3] = 1;
	int N;
	scanf("%d", &N);
	for (int n = 4; n <= N; n++){
		pibonacci[n] = pibonacci[n - 1] + pibonacci[n - 3];
	}
	printf("%lld", pibonacci[N]);
}