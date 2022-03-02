// 2447 별 찍기 - 10
#include <stdio.h>
#include <math.h>

char shiny[2200][2200];

void star(int n, int x, int y){
	//printf("hmm\n");
	if (n == 1){
		shiny[x][y] = '*';
		return;
	}
	int k = n / 3;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (i == 1 && j == 1){
				continue;
			}
			star(k, x + k * i, y + k * j);
		}
	}
	return;
}

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			shiny[i][j] = ' ';
		}
	}
	//printf("hmm\n");
	star(N, 0, 0);
	//printf("hmm\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c", shiny[i][j]);
		}
		printf("\n");
	}
}