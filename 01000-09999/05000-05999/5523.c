// 5523 경기 결과
// https://www.acmicpc.net/problem/5523
#include <stdio.h>

int main(){
	int Ascore = 0, Bscore = 0, A, B, N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &A, &B);
		if (A > B){Ascore++;}
		else if (A < B){Bscore++;}
	}
	printf("%d %d", Ascore, Bscore);
}