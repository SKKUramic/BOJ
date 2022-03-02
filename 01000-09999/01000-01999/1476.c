// 1476 날짜 계산
// https://www.acmicpc.net/problem/1476
#include <stdio.h>

int main(){
	int E, S, M, year = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (E != 1 || S != 1 || M != 1){
		E--; S--; M--; year++;
		if (E == 0){E = 15;}
		if (S == 0){S = 28;}
		if (M == 0){M = 19;}
	}
	printf("%d", year);
}