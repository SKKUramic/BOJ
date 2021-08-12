// 11586 지영 공주님의 마법 거울
// https://www.acmicpc.net/problem/11586
#include <stdio.h>
#include <stdlib.h>

char mirror[101][101];

int main(){
	int N, angry;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%s", mirror[n]);
	}
	scanf("%d", &angry);
	if (angry == 1){
		for (int n = 0; n < N; n++){
			printf("%s\n", mirror[n]);
		}
	}
	else if (angry == 2){
		for (int i = 0; i < N; i++){
			for (int j = N - 1; j >= 0; j--){
				printf("%c", mirror[i][j]);
			}
			printf("\n");
		}
	}
	else if (angry == 3){
		for (int i = N - 1; i >= 0; i--){
			printf("%s\n", mirror[i]);
		}
	}
}