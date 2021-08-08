// 17174 전체 계산 횟수
// https://www.acmicpc.net/problem/17174
#include <stdio.h>

int main(){
	int N, M, count = 0;
	scanf("%d %d", &N, &M);
	while (N > 0){
		count += N;
		N /= M;
	}
	printf("%d", count);
}