// 3049 다각형의 대각선
// https://www.acmicpc.net/problem/3049
#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", N * (N - 1) * (N - 2) * (N - 3) / 24);
}