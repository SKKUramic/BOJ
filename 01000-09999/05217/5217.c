// 5217 쌍의 합
// https://www.acmicpc.net/problem/5217
#include <stdio.h>

int main(){
	int TC, N;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &N);
		printf("Pairs for %d:", N);
		for (int i = 1; i * 2 < N; i++){
			printf(" %d %d", i, N - i);
			if ((i + 1) * 2 < N){printf(",");}
		}
		printf("\n");
	}
}