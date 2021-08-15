// 2873 롤러코스터
// https://www.acmicpc.net/problem/2873
#include <stdio.h>

int roller[1000][1000];

int main(){
	// R이랑 C 중 어느 하나라도 홀수라면 모든 영역을 지나갈 수 있다
	// 둘 다 짝수일 때, arr[i][j]에서 i + j가 홀수인 칸 하나만 배제하면 모든 칸을 지날 수 있다
	// i + j가 짝수이면 i + j가 홀수인 칸이 적어도 하나 같이 배제되므로 고려할 필요가 없다(왜인지는 모르겠음)
	int R, C;
	scanf("%d %d", &R, &C);
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			scanf("%d", &roller[r][c]);
		}
	}
	if (R % 2 == 1){
		for (int r = 0; r < R; r++){
			if (r % 2 == 0){
				for (int c = 0; c < C - 1; c++){
					printf("R");
				}
			}
			else {
				for (int c = 0; c < C - 1; c++){
					printf("L");
				}
			}
			if (r != R - 1){printf("D");}
		}
	}
	else if (C % 2 == 1){
		for (int c = 0; c < C; c++){
			if (c % 2 == 0){
				for (int r = 0; r < R - 1; r++){
					printf("D");
				}
				
			}
			else {
				for (int r = 0; r < R - 1; r++){
					printf("U");
				}
			}
			if (c != C - 1){printf("R");}
		}
	}
	else {
		int min_happy = roller[0][1];
		int min_y = 0, min_x = 1;
		for (int r = 0; r < R; r++){
			for (int c = (r + 1) % 2; c < C; c += 2){
				if (roller[r][c] < min_happy){
					min_happy = roller[r][c];
					min_y = r;
					min_x = c;
				}
			}
		}
		for (int r = 0; r < min_y - min_y % 2; r += 2){
			for (int c = 0; c < C - 1; c++){
				printf("R");	
			}
			printf("D");
			for (int c = 0; c < C - 1; c++){
				printf("L");
			}
			printf("D");
		}
		for (int c = 0; c < min_x - min_x % 2; c += 2){
			printf("DRUR");
		}
		if (min_x % 2 == 1){printf("DR");}
		else {printf("RD");}
		for (int c = (min_x + 2) - (min_x % 2); c < C; c += 2){
			printf("RURD");
		}
		for (int r = (min_y + 2) - (min_y % 2); r < R; r += 2){
			printf("D");
			for (int c = 0; c < C - 1; c++){
				printf("L");
			}
			printf("D");
			for (int c = 0; c < C - 1; c++){
				printf("R");	
			}
		}
	}
}