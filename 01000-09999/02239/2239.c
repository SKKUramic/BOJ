// 2239 스도쿠
// https://www.acmicpc.net/problem/2239
#include <stdio.h>

int sudoku[10][10] = {0, };
int find = 0;

int is_valid(int idx, int input){
	int y_idx = idx / 9;
	int x_idx = idx % 9;
	int y_start = (y_idx / 3) * 3;
	int x_start = (x_idx / 3) * 3;
	for (int y = 0; y < 9; y++){
		if (y != y_idx && sudoku[y][x_idx] == input){return 0;}
	}
	for (int x = 0; x < 9; x++){
		if (x != x_idx && sudoku[y_idx][x] == input){return 0;}
	}
	for (int y = y_start; y < y_start + 3; y++){
		for (int x = x_start; x < x_start + 3; x++){
			if ((y != y_idx || x != x_idx) && sudoku[y][x] == input){return 0;}
		}
	}
	return 1;
}

void DFS(int idx){
	int y_idx = idx / 9;
	int x_idx = idx % 9;
	if (find == 1){return;}
	if (idx == 81){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				printf("%d", sudoku[i][j]);
			}
			printf("\n");
		}
		find = 1;
		return;
	}
	if (sudoku[y_idx][x_idx] != 0){
		DFS(idx + 1);
		return;
	} // 이미 숫자가 들어간 칸일 경우 스킵함
	for (int i = 1; i <= 9; i++){
		if (is_valid(idx, i) == 1){
			sudoku[y_idx][x_idx] = i;
			DFS(idx + 1);
		}
	}
	sudoku[y_idx][x_idx] = 0; // 여기까지 왔다는 건 이 좌표의 수는 원래 0이었다는 뜻
	return;
}

int main(){
	char s[10];
	for (int i = 0; i < 9; i++){
		scanf("%s", s);
		for (int j = 0; j < 9; j++){
			sudoku[i][j] = s[j] - '0';
		}
	}
	DFS(0);
	
}