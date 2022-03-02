// 2448 별 찍기 - 11
// https://www.acmicpc.net/problem/2448
// 모든 줄은 같은 수의 문자를 출력해야 함
#include <stdio.h>

char STAR[7000][7000];

void print_star(int n, int line, int idx){ // (line, idx): 삼각형의 위 꼭짓점을 가리킴
	if (n == 3){
		STAR[line][idx] = '*';
		STAR[line + 1][idx - 1] = '*';
		STAR[line + 1][idx] = ' ';
		STAR[line + 1][idx + 1] = '*';
		STAR[line + 2][idx - 2] = '*';
		STAR[line + 2][idx - 1] = '*';
		STAR[line + 2][idx] = '*';
		STAR[line + 2][idx + 1] = '*';
		STAR[line + 2][idx + 2] = '*';
		return;
	}
	print_star(n / 2, line, idx);
	print_star(n / 2, line + n / 2, idx - n / 2);
	print_star(n / 2, line + n / 2, idx + n / 2);
}

int main(){
	//FILE *fp = fopen("2448.txt", "w");
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 2 * N; j++){
			if (j == 2 * N - 1){
				STAR[i][j] = '\0';
			}
			else {
				STAR[i][j] = ' ';
			}
		}
	}
	print_star(N, 0, N - 1);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 2 * N - 1; j++){
			printf("%c", STAR[i][j]);
			//fprintf(fp, "%c", STAR[i][j]);
		}
		printf("\n");
		//fprintf(fp, "\n");
	}
	//fclose(fp);
}