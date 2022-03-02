// 3076 상근이의 체스판
// https://www.acmicpc.net/problem/3076
#include <stdio.h>

char board[101][101];
char color[2] = {'X', '.'};

int main(){
	int R, C, A, B, idx = 0;
	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);
	for (int y = 0; y < R; y++){
		for (int x = 0; x < C; x++){
			for (int i = y * A; i < y * A + A; i++){
				for (int j = x * B; j < x * B + B; j++){
					board[i][j] = color[idx];
				}
			}
			idx = (idx + 1) % 2;
		}
		if (C % 2 == 0){idx = (idx + 1) % 2;}
	}
	for (int y = 0; y < R * A; y++){
		for (int x = 0; x < C * B; x++){
			printf("%c", board[y][x]);
		}
		printf("\n");
	}
}