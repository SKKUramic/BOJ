// 10997 별 찍기 - 22
// https://www.acmicpc.net/problem/10997
// 가로 별 개수는 4n - 3, 세로 별 개수는 4n - 1(단, n == 1일 때는 둘 다 1)
#include <stdio.h>

char STAR[500][500];

void init(int n){
	for (int i = 0; i < 4 * n - 1; i++){
		for (int j = 0; j < 4 * n - 3; j++){
			STAR[i][j] = ' ';
		}
	}
	return;
}

void print(int n){
	for (int i = 0; i < 4 * n - 1; i++){
		for (int j = 0; j < 4 * n - 3; j++){
			if (i == 1 && j == 1){break;} // 출력 형식이 잘못되었습니다 방지
			printf("%c", STAR[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(){
	int N, LINE, IDX, line, idx;
	scanf("%d", &N);
	if (N == 1){
		printf("*\n");
		return 0;
	}
	init(N);
	LINE = 4 * N - 2; IDX = 4 * N - 4;
	line = 0; idx = IDX;
	while (line != 2 * N && idx != 2 * N - 2){ // 왼쪽, 아래, 오른쪽, 위 순서로 별을 찍음
		while(idx > 0 && STAR[line][idx - 2] != '*'){
			STAR[line][idx--] = '*';
		}
		while(line < LINE && STAR[line + 2][idx] != '*'){
			STAR[line++][idx] = '*';
		}
		while(idx < IDX && STAR[line][idx + 2] != '*'){
			STAR[line][idx++] = '*';
		}
		while(line > 0 && STAR[line - 2][idx] != '*'){
			STAR[line--][idx] = '*';
		}
	}
	STAR[line][idx] = '*';
	print(N);
	return 0;
}