// 2446 별 찍기 - 9
#include <stdio.h>
//#include <stdlib.h>

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < i; j++){
			printf(" ");
		}
		for (int j = i + 1; j < 2 * N - i; j++){
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i < N; i++){
		for (int j = 0; j < N - i - 1; j++){
			printf(" ");
		}
		for (int j = N - i; j < N + i + 1; j++){
			printf("*");
		}
		//sleep(1);
		printf("\n");
	}
}