// 18883 N M 찍기
#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (j == M - 1){
				printf("%d", M * i + j + 1);
			}
			else {
				printf("%d ", M * i + j + 1);	
			}
		}
		printf("\n");
	}
}