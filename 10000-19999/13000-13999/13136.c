// 13136 Do Not Touch Anything
// https://www.acmicpc.net/problem/13136
#include <stdio.h>

int main(){
	long long R, C, N;
	long long row, col, answer;
	scanf("%lld %lld %lld", &R, &C, &N);
	row = R / N + (R % N == 0 ? 0 : 1);
	col = C / N + (C % N == 0 ? 0 : 1);
	answer = row * col;
	printf("%lld", answer);
}