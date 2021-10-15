// 17143 낚시왕
// https://www.acmicpc.net/problem/17143
#include <stdio.h>

typedef struct Shark{
	int speed;
	int direction;
	int size;
}Shark;

Shark WaterTank[101][101], temp[101][101];
int dy[5] = {0, -1, 1, 0, 0}, dx[5] = {0, 0, 0, 1, -1};
int R, C, M;

void initialize(){
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			WaterTank[i][j].speed = -1;
			WaterTank[i][j].direction= -1;
			WaterTank[i][j].size = -1;
		}
	}
	return;
}

void printWaterTank(){
	printf("Current Tank\n");
	for (int r = 1; r <= R; r++){ // 예측 장소 반영
		for (int c = 1; c <= C; c++){
			printf("% 4d", WaterTank[r][c].size);
		}
		printf("\n");
	}
}

int main(){
	int r, c, next_r, move_r, next_c, move_c, answer = 0;
	int Speed, Size, Dir;
	initialize();
	scanf("%d %d %d", &R, &C, &M);
	for (int m = 0; m < M; m++){
		scanf("%d %d", &r, &c);
		scanf("%d %d %d", &WaterTank[r][c].speed, &WaterTank[r][c].direction, &WaterTank[r][c].size);
	}
	for (int c = 1; c <= C; c++){
		Got = 0;
		for (int r = 1; r <= R; r++){ // 상어 잡기
			if (WaterTank[r][c].speed != -1){ // 빈 칸이 아닐 때
				answer += WaterTank[r][c].size; // 상어를 낚아챔
				WaterTank[r][c].speed = -1; // 상어 없애기
				WaterTank[r][c].direction = -1;
				WaterTank[r][c].size = -1;
				Got = 1;
				break;
			}
		}
		for (int i = 0; i <= 100; i++){ // temparr 초기화
			for (int j = 0; j <= 100; j++){
				temp[i][j].speed = -1;
				temp[i][j].direction= -1;
				temp[i][j].size = -1;
			}
		}
		for (int rr = 1; rr <= R; rr++){ // 이동할 장소 예측
			for (int cc = 1; cc <= C; cc++){
				Speed = WaterTank[rr][cc].speed;
				Dir = WaterTank[rr][cc].direction;
				Size = WaterTank[rr][cc].size;
				next_r = rr;
				next_c = cc;
				if (Size == -1){continue;}
				if (Dir == 1 || Dir == 2){
					if (R == 1){move_r = 0;}
					else {move_r = (Speed % (2 * R - 2)) * dy[Dir];}
					while (next_r + move_r < 1 || next_r + move_r > R){
						if (next_r + move_r < 1){ // move_r < 0, UP
							move_r = -move_r - (next_r - 1);
							next_r = 1;
							Dir = 2;
						}
						else if (next_r + move_r > R){ // move_r > 0, DOWN
							move_r = -move_r + (R - next_r);
							next_r = R;
							Dir = 1;
						}
					}
					next_r += move_r;
				}
				else if (Dir == 3 || Dir == 4){
					if (C == 1){move_c = 0;}
					else {move_c = (Speed % (2 * C - 2)) * dx[Dir];}
					while (next_c + move_c < 1 || next_c + move_c > C){
						if (next_c + move_c < 1){ // move_c < 0, LEFT
							move_c = -move_c - (next_c - 1);
							next_c = 1;
							Dir = 3;
						}
						else if (next_c + move_c > C){ // move_c > 0, RIGHT
							move_c = -move_c + (C - next_c);
							next_c = C;
							Dir = 4;
						}
					}
					next_c += move_c;
				}
				if (temp[next_r][next_c].speed == -1 || temp[next_r][next_c].size < WaterTank[rr][cc].size){ // 처음 도착했거나, 겹치지만 들어온 상어가 더 클 때
					temp[next_r][next_c].speed = WaterTank[rr][cc].speed;
					temp[next_r][next_c].direction = Dir;
					temp[next_r][next_c].size = WaterTank[rr][cc].size;
				}
			}
		}
		for (int rr = 1; rr <= R; rr++){ // 예측 장소 반영
			for (int cc = 1; cc <= C; cc++){
				WaterTank[rr][cc].speed = temp[rr][cc].speed;
				WaterTank[rr][cc].direction = temp[rr][cc].direction;
				WaterTank[rr][cc].size = temp[rr][cc].size;
			}
		}
	}
	printf("%d", answer);
}