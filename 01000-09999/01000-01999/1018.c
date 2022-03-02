// 1018 체스판 다시 칠하기
#include <stdio.h>

char chessboard[50][50];

int main(){
	char color;
	int N, M, min = 100, count = 0;
	int n, m;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%s", chessboard[i]);
	}
	n = N - 8; m = M - 8;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			color = chessboard[i][j];
			count = 0;
			//printf("i:%d, j:%d\n", i, j);
			for (int x = i; x < i + 8; x++){
				for (int y = j; y < j + 8; y++){
					//printf("%c", chessboard[x][y]);
					if (color != chessboard[x][y]){
						count++;
						//printf("%d | %d change\n", x, y);
					}
					if (y != j + 7){
						if (color == 'W'){color = 'B';}
						else {color = 'W';}
					}
				}
				//printf("\n");
			}
			//printf("\n");
			if (count > 32){count = 64 - count;}
			if (count < min){min = count;}
			//printf("count: %d, min: %d\n\n", count, min);
		}
	}
	printf("%d", min);
}