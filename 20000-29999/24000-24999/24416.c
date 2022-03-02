// 24416 알고리즘 수업 - 피보나치 수 1
// https://www.acmicpc.net/problem/24416
#include <stdio.h>

long long Fibonacci[41] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	Fibonacci[1] = 1; Fibonacci[2] = 1;
	for (int n = 3; n <= 40; n++){
		Fibonacci[n] = Fibonacci[n - 1] + Fibonacci[n - 2];
	}
	printf("%lld %d", Fibonacci[N], N - 2);
}