// 4108 지뢰 찾기
// https://www.acmicpc.net/problem/4108
#include <stdio.h>

char mine[102][102];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
	int R, C;
	char str[101], number;
	scanf("%d %d", &R, &C);
	while (R != 0 || C != 0){
		for (int r = 1; r <= R; r++){
			scanf("%s", str);
			for (int c = 1; c <= C; c++){
				mine[r][c] = str[c - 1];
			}
		}
		for (int r = 0; r <= R + 1; r++){
			mine[r][0] = '.';
			mine[r][C + 1] = '.';
		}
		for (int c = 0; c <= C + 1; c++){
			mine[0][c] = '.';
			mine[R + 1][c] = '.';
		}
		for (int r = 1; r <= R; r++){
			for (int c = 1; c <= C; c++){
				if (mine[r][c] != '*'){
					number = '0';
					for (int k = 0; k < 8; k++){
						if (mine[r + dy[k]][c + dx[k]] == '*'){number++;}
					}
					mine[r][c] = number;
				}
				printf("%c", mine[r][c]);
			}
			printf("\n");
		}
		scanf("%d %d", &R, &C);
	}
}