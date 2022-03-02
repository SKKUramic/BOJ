// 11179 2진수 뒤집기
// https://www.acmicpc.net/problem/11179
#include <stdio.h>

int main(){
	int N, idx = 0;
	int two[100];
	scanf("%d", &N);
	while (N > 0){
		two[idx++] = N % 2;
		N /= 2;
	}
	for (int i = 0; i < idx; i++){
		N = N * 2 + two[i];
	}
	printf("%d", N);
}