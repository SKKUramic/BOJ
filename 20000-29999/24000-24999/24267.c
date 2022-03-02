// 24267 알고리즘 수업 - 알고리즘의 수행 시간 6
// https://www.acmicpc.net/problem/24267
#include <stdio.h>

int main(){
	long long N;
	scanf("%lld", &N);
	printf("%lld\n3\n", N * (N - 1) * (N - 2) / 6);
}