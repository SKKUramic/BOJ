// 2580 스도쿠
#include <stdio.h>
#include <stdbool.h>

int sudoku[9][9];
bool flags = false;

bool print_sudoku(){
	for (int a = 0; a < 9; a++){
		for (int b = 0; b < 9; b++){
			if (sudoku[a][b] == 0){return false;}
		}
	}
	for (int a = 0; a < 9; a++){
		for (int b = 0; b < 9; b++){
			printf("%d ", sudoku[a][b]);
		}
		printf("\n");
	}
	return true;
}

bool horizontal_check(int x){
	int number_tf[10] = {0, };
	int temp;
	for (int i = 0; i < 9; i++){
		temp = sudoku[x][i];
		if (temp != 0){
			number_tf[temp]++;
			if (number_tf[temp] > 1){
				return false;
			}
		}
	}
	return true;
}

bool vertical_check(int y){
	int number_tf[10] = {0, };
	int temp;
	for (int j = 0; j < 9; j++){
		temp = sudoku[j][y];
		if (temp != 0){
			number_tf[temp]++;
			if (number_tf[temp] > 1){
				return false;
			}
		}
	}
	return true;
}

bool square_check(int xx, int yy){
	int x, y, temp;
	int number_tf[10] = {0, };
	if (xx < 3){x = 0;}
	else if (xx < 6) {x = 3;}
	else {x = 6;}
	if (yy < 3){y = 0;}
	else if (yy < 6) {y = 3;}
	else {y = 6;}
	for (int i = x; i < x + 3; i++){
		for (int j = y; j < y + 3; j++){
			temp = sudoku[i][j];
			if (temp != 0){
				number_tf[temp]++;
				if (number_tf[temp] > 1){
					return false;
				}
			}
		}
	}
	return true;
}

void solving_sudoku(int x, int y){
	if (flags == true) {return;}
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (sudoku[i][j] == 0){
				for (int k = 1; k <= 9; k++){
					sudoku[i][j] = k;
					if (horizontal_check(i) && vertical_check(j) && square_check(i, j)){
						solving_sudoku(i, j);
					}
					sudoku[i][j] = 0;
				}
				return;
			}
			if (i == 8 && j == 8){
				flags = print_sudoku();
			}
		}
	}
	return;
}

int main(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			scanf("%d", &sudoku[i][j]);
		}
	}
	solving_sudoku(0, 0);
	return 0;
}