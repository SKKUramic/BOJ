// 1030 프렉탈 평면
// https://www.acmicpc.net/problem/1030
#include <stdio.h>

int s, N, K;

int black_and_white(int time, int r, int c){
	if (time == -1){return 0;}
	if ((r % N >= (N - K) / 2 && r % N < (N + K) / 2) && (c % N >= (N - K) / 2 && c % N < (N + K) / 2)){return 1;}
	else {return 0;}
}

int main(){
	int R1, R2, C1, C2;
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	for (int r = R1; r <= R2; r++){
		for (int c = C1; c <= C2; c++){
			printf("%d", black_and_white(s - 1, r, c));
		}
		printf("\n");
	}
}