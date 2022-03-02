// 11383 뚊
#include <stdio.h>

char doldom[10][10];
char dd[20][20];

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%s", doldom[i]);
	}
	for (int i = 0; i < N; i++){
		scanf("%s", dd[i]);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (doldom[i][j] != dd[i][2 * j] || doldom[i][j] != dd[i][2 * j + 1]){
				printf("Not Eyfa");
				return 0 ;
			}
		}
	}
	printf("Eyfa");
	return 0;
}