// 3041 N-퍼즐
// https://www.acmicpc.net/problem/3041
#include <stdio.h>
#include <stdlib.h>

char puzzle[4][4];

int main(){
	int manhattan = 0, Yidx, Xidx;
	for (int i = 0; i < 4; i++){
		scanf("%s", puzzle[i]);
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (puzzle[i][j] != '.'){
				Yidx = (puzzle[i][j] - 'A') / 4;
				Xidx = (puzzle[i][j] - 'A') % 4;
				manhattan += abs(i - Yidx) + abs(j - Xidx);
			}
		}
	}
	printf("%d", manhattan);
}