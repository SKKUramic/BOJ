// 1051 숫자 정사각형
// https://www.acmicpc.net/problem/1051
#include <stdio.h>

int square[50][50];
char number[50];

int main(){
	int N, max_row, max_col, len;
	int max_size = 1;
	scanf("%d %d", &max_row, &max_col);
	for (int r = 0; r < 50; r++){
		for (int c = 0; c < 50; c++){
			square[r][c] = -1;
		}
	}
	for (int r = 0; r < max_row; r++){
		scanf("%s", number);
		for (int c = 0; c < max_col; c++){
			square[r][c] = number[c] - '0';
		}
	}
	for (int r = 0; r < max_row; r++){
		for (int c = 0; c < max_col; c++){
			len = 0;
			while (r + len < max_row && c + len < max_col){
				if (square[r][c] == square[r + len][c] && square[r + len][c] == square[r][c + len] && square[r][c + len] == square[r + len][c + len]){
					if ((len + 1) * (len + 1) > max_size){
						max_size = (len + 1) * (len + 1);
					}
				}
				len++;
			}
			//printf("max_size: %d\n", max_size);
		}
	}
	printf("%d", max_size);
}