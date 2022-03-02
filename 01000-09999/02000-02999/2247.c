// 2247 실질적 약수
// https://www.acmicpc.net/problem/2247
#include <stdio.h>

int main(){
	long long int answer = 0;
	int N, idx;
	scanf("%d", &N);
	idx = N / 2 + 1;
	for (int i = 2; i < idx; i++){
		answer += ((N / i) - 1) * i;
		answer %= 1000000;
	}
	printf("%lld", answer);
}