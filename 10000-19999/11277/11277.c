// 11277 2-SAT - 1
// https://www.acmicpc.net/problem/11277
#include <stdio.h>
#include <stdlib.h>

int N, M;
int boolean[21] = {0, };
int cluase[101][2];

int twoSAT(int bool_value){
	int isTrue = 1, a, b;
	for (int i = 1; i <= N; i++){
		boolean[i] = bool_value % 2;
		bool_value /= 2;
	}
	for (int m = 0; m < M; m++){
		a = ((cluase[m][0] < 0 ? 0 : 1) ^ boolean[abs(cluase[m][0])]) ? 0 : 1;
		b = ((cluase[m][1] < 0 ? 0 : 1) ^ boolean[abs(cluase[m][1])]) ? 0 : 1;
		isTrue &= (a | b);
	}
	return isTrue;
}

int main(){
	int answer = 0;
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++){
		scanf("%d %d", &cluase[m][0], &cluase[m][1]);
	}
	for (int i = 0; i < (1 << N) && answer == 0; i++){
		answer |= twoSAT(i);
	}
	printf("%d", answer);
}