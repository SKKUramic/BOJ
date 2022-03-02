// 9291 스도쿠 채점
// https://www.acmicpc.net/problem/9291
#include <stdio.h>

int sudoku[9][9];
int number[10] = {0, };
int is_correct[3][9] = {0, };
int answer[101] = {0, };
int dx[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
int dy[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};

int main(){
	int TC, x, y, invalid;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++){
		invalid = 0;
		for (int i = 1; i <= 9; i++){
			number[i] = 0;
		}
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				scanf("%d", &sudoku[i][j]);
				number[sudoku[i][j]]++;
			}
		}
		for (int i = 1; i <= 9; i++){
			if (number[i] != 9){
				invalid = 1;
				break;
			}
		}
		if (invalid){
			answer[tc] = -1;
			continue;
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 9; j++){
				is_correct[i][j] = 0;
			}
		}
		for (int i = 0; i < 9; i++){
			x = dx[i]; y = dy[i];
			for (int j = 0; j < 9; j++){
				is_correct[0][i] += sudoku[i][j]; // 가로
				is_correct[1][i] += sudoku[j][i]; // 세로
				is_correct[2][i] += sudoku[x + j / 3][y + j % 3]; // 3x3
			}
		}
		for (int i = 0; i < 27; i++){
			if (is_correct[i / 9][i % 9] != 45){
				answer[tc] = -1;
				break;
			}
		}
	}
	for (int tc = 1; tc <= TC; tc++){
		if (answer[tc] == -1){printf("Case %d: INCORRECT\n", tc);}
		else {printf("Case %d: CORRECT\n", tc);}
	}
}