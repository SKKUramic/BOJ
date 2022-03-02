// 2615 오목
// https://www.acmicpc.net/problem/2615
#include <stdio.h>

int board[21][21] = {0, };

int main(){
	int win = -1, win_x, win_y;
	for (int i = 1; i < 20; i++){
		for (int j = 1; j < 20; j++){
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 1; i < 20; i++){
		for (int j = 1; j < 20; j++){
			if (i <= 15){
				if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j] && board[i][j] != board[i - 1][j] && board[i + 4][j] != board[i + 5][j]){
					win = board[i][j]; win_y = i; win_x = j;
					break;
				}
			}
			if (j <= 15){
				if (board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != board[i][j - 1] && board[i][j + 4] != board[i][j + 5]){
					win = board[i][j]; win_y = i; win_x = j;
					break;
				}
			}
			if (i <= 15 && j <= 15){
				if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != board[i - 1][j - 1] && board[i + 4][j + 4] != board[i + 5][j + 5]){
					win = board[i][j]; win_y = i; win_x = j;
					break;
				}
			}
			if (i <= 15 && j >= 5){
				if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 2][j - 2] == board[i + 3][j - 3] && board[i + 3][j - 3] == board[i + 4][j - 4] && board[i][j] != board[i - 1][j + 1] && board[i + 4][j - 4] != board[i + 5][j - 5]){
					win = board[i][j]; win_y = i + 4; win_x = j - 4;
					break;
				}
			}
		}
	}
	if (win == -1){printf("0");}
	else {
		printf("%d\n%d %d", win, win_y, win_x);
	}
}