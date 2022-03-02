// 24265 알고리즘 수업 - 알고리즘의 수행 시간 4
// https://www.acmicpc.net/problem/24265
#include <stdio.h>

int main(){
	long long N;
	scanf("%lld", &N);
	printf("%lld\n2\n", N * (N - 1) / 2);
}