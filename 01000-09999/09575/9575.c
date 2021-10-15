// 9575 행운의 수
// https://www.acmicpc.net/problem/9575
#include <stdio.h>

int A[51], B[51], C[51];
int N, M, K;
int Lucky[100000] = {0, };
int used[100000] = {0, };

void initialize(){
	Lucky[5] = 1; Lucky[8] = 1;
	for (int k = 10; k <= 100000; k++){
		if (Lucky[k / 10] == 1 && (k % 10 == 5 || k % 10 == 8)){Lucky[k] = 1;}
	}
	return;
}

int main(){
	int TC, cnt;
	scanf("%d", &TC);
	initialize();
	while (TC-- > 0){
		cnt = 0;
		for (int k = 0; k <= 100000; k++){used[k] = 0;}
		scanf("%d", &N);
		for (int a = 0; a < N; a++){scanf("%d", &A[a]);}
		scanf("%d", &M);
		for (int b = 0; b < M; b++){scanf("%d", &B[b]);}
		scanf("%d", &K);
		for (int c = 0; c < K; c++){scanf("%d", &C[c]);}
		for (int a = 0; a < N; a++){
			for (int b = 0; b < M; b++){
				for (int c = 0; c < K; c++){
					if (Lucky[A[a] + B[b] + C[c]] == 1 && used[A[a] + B[b] + C[c]] == 0){
						cnt++;
						used[A[a] + B[b] + C[c]] = 1;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}