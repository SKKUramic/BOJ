// 5604 問題3
// JOI 제5회 본선 문제3입니다.
// 자연수의 분할을 구현하는 문제
// https://www.acmicpc.net/problem/5604
#include <stdio.h>

int S[100];
int N, S_index = 0;

void square_sqaure(int T, int n){
	if (T <= 0){
		for (int i = 0; i < S_index; i++){
			printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	for (int i = T; i > 0; i--){
		if (S[S_index - 1] < i) {continue;}
		S[S_index++] = i;
		square_sqaure(T - i, i);
		S[--S_index] = -1;
	}
}

int main(){
	scanf("%d", &N);
	for (int i = N; i > 0; i--){
		S[S_index++] = i;
		square_sqaure(N - i, i);
		S[--S_index] = -1;
	}
}