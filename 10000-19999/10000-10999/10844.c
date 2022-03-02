// 10844 쉬운 계단 수
#include <stdio.h>
#define MODULO 1000000000

int endnum_count[10][101] = {0, };

int main(){
	int N, answer = 0;
	scanf("%d", &N);
	for (int i = 1; i < 10; i++){
		endnum_count[i][1] = 1;
	}
	for (int i = 2; i <= N; i++){
		for (int x = 0; x < 10; x++){
			if (x == 0){
				endnum_count[x][i] = endnum_count[x + 1][i - 1] % MODULO;
			}
			else if (x == 9){
				endnum_count[x][i] = endnum_count[x - 1][i - 1] % MODULO;
			}
			else {
				endnum_count[x][i] = (endnum_count[x - 1][i - 1] + endnum_count[x + 1][i - 1]) % MODULO;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		//printf("%d ", endnum_count[i][N]);
		answer = (answer + endnum_count[i][N]) % MODULO;
	}
	printf("%d", answer);
}