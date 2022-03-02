//2522 별 찍기 - 12
#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 2 * N - 1; i++){
		if (i < N){
			for (int j = 0; j < N - i - 1; j++){
				printf(" ");
			}
			for (int j = N - i - 1; j < N; j++){
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int j = 0; j < i - N + 1; j++){
				printf(" ");
			}
			for (int j = i - N + 1; j < N; j++){
				printf("*");
			}
			printf("\n");
		}
	}
}