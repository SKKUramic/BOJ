// 2578 빙고
// https://www.acmicpc.net/problem/2578
#include <stdio.h>

int bingo[5][5], call[25];
int bingo_idx = -1;

void makeBINGO(int idx){
	int bingo_count = 0;
	if (bingo[0][0] + bingo[1][1] + bingo[2][2] + bingo[3][3] + bingo[4][4] == -5){bingo_count++;}
	if (bingo[4][0] + bingo[3][1] + bingo[2][2] + bingo[1][3] + bingo[0][4] == -5){bingo_count++;}
	for (int i = 0; i < 5; i++){
		if (bingo[i][0] + bingo[i][1] + bingo[i][2] + bingo[i][3] + bingo[i][4] == -5){bingo_count++;}
		if (bingo[0][i] + bingo[1][i] + bingo[2][i] + bingo[3][i] + bingo[4][i] == -5){bingo_count++;}
	}
	if (bingo_count >= 3 && bingo_idx == -1){bingo_idx = idx + 1;}
	return;
}

int main(){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			scanf("%d", &bingo[i][j]);
		}
	}
	for (int i = 0; i < 25; i++){
		scanf("%d", &call[i]);
	}
	for (int x = 0; x < 25; x++){
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (bingo[i][j] == call[x]){
					bingo[i][j] = -1;
					makeBINGO(x);
				}
			}
		}	
	}
	printf("%d", bingo_idx);
}