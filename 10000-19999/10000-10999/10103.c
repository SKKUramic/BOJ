// 10103 주사위 게임
// https://www.acmicpc.net/problem/10103
#include <stdio.h>

int main(){
	int Cscore = 100, Sscore = 100;
	int round, C, S;
	scanf("%d", &round);
	for (int r = 0; r < round; r++){
		scanf("%d %d", &C, &S);
		if (C < S){
			Cscore -= S;
		}
		else if (C > S){
			Sscore -= C;
		}
	}
	printf("%d\n%d", Cscore, Sscore);
}