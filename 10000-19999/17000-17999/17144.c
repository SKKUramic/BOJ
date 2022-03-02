// 17144 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
#include <stdio.h>

int spread_dirt[51][51] = {0, };
int temp_arr[51][51] = {0, };
int air_cleaner[2][2] = {0, };
int R, C, T, dirt, dirt_sum = 0;

void ccw(){ // 윗부분을 시계 반대방향으로 돌림
	int r = air_cleaner[0][0];
	int c = air_cleaner[0][1];
	while (r > 1){
		temp_arr[r][c] = temp_arr[r - 1][c];
		r--;
	}
	while (c < C){
		temp_arr[r][c] = temp_arr[r][c + 1];
		c++;
	}
	while (r < air_cleaner[0][0]){
		temp_arr[r][c] = temp_arr[r + 1][c];
		r++;
	}
	while (air_cleaner[0][1] < c){
		temp_arr[r][c] = temp_arr[r][c - 1];
		c--;
	}
	temp_arr[r][c] = -1; // 공기청정기가 있는 자리
	temp_arr[r][c + 1] = 0; // 공기청정기 오른쪽 칸은 공기가 정화됨
	return;
}

void cw(){ // 아랫쪽 부분을 시계방향으로 돌림
	int r = air_cleaner[1][0];
	int c = air_cleaner[1][1];
	while (r < R){
		temp_arr[r][c] = temp_arr[r + 1][c];
		r++;
	}
	while (c < C){
		temp_arr[r][c] = temp_arr[r][c + 1];
		c++;
	}
	while (air_cleaner[1][0] < r){
		temp_arr[r][c] = temp_arr[r - 1][c];
		r--;
	}
	while (air_cleaner[1][1] < c){
		temp_arr[r][c] = temp_arr[r][c - 1];
		c--;
	}
	temp_arr[r][c] = -1; // 공기청정기가 있는 자리
	temp_arr[r][c + 1] = 0; // 공기청정기 오른쪽 칸은 공기가 정화됨
	return;
}

int main(){
	scanf("%d %d %d", &R, &C, &T);
	for (int r = 1; r <= R; r++){
		for (int c = 1; c <= C; c++){
			scanf("%d", &spread_dirt[r][c]);
			if (spread_dirt[r][c] == -1){
				if (air_cleaner[0][0] == 0){
					air_cleaner[0][0] = r;
					air_cleaner[0][1] = c;
				}
				else {
					air_cleaner[1][0] = r;
					air_cleaner[1][1] = c;
				}
			}
		}
	}
	while (T-- > 0){
		for (int r = 1; r <= R; r++){for (int c = 1; c <= C; c++){temp_arr[r][c] = 0;}} // 초기화
		for (int r = 1; r <= R; r++){
			for (int c = 1; c <= C; c++){
				if (spread_dirt[r][c] == -1){continue;} // 혹시 모르니 공기청정기가 있는 자리는 바로 스킵
				temp_arr[r][c] += spread_dirt[r][c];
				if (spread_dirt[r][c] < 5){continue;} // 먼지 수치가 5 이하라면 확산되지 않음
				dirt = spread_dirt[r][c] / 5;
				if (r > 1 && spread_dirt[r - 1][c] != -1){ // 먼지가 퍼지려는 자리가 유효하고, 공기청정기가 없을 때
					temp_arr[r][c] -= dirt;
					temp_arr[r - 1][c] += dirt;
				}
				if (r < R && spread_dirt[r + 1][c] != -1){
					temp_arr[r][c] -= dirt;
					temp_arr[r + 1][c] += dirt;
				}
				if (c > 1 && spread_dirt[r][c - 1] != -1){
					temp_arr[r][c] -= dirt;
					temp_arr[r][c - 1] += dirt;
				}
				if (c < C && spread_dirt[r][c + 1] != -1){
					temp_arr[r][c] -= dirt;
					temp_arr[r][c + 1] += dirt;
				}
			}
		}
		temp_arr[air_cleaner[0][0]][air_cleaner[0][1]] = -1;
		temp_arr[air_cleaner[1][0]][air_cleaner[1][1]] = -1;
		ccw();
		cw();
		for (int r = 1; r <= R; r++){for (int c = 1; c <= C; c++){spread_dirt[r][c] = temp_arr[r][c];}}
		spread_dirt[air_cleaner[0][0]][air_cleaner[0][1]] = -1;
		spread_dirt[air_cleaner[1][0]][air_cleaner[1][1]] = -1;
	}
	for (int r = 1; r <= R; r++){
		for (int c = 1; c <= C; c++){
			if (spread_dirt[r][c] != -1) {dirt_sum += spread_dirt[r][c];}
		}
	}
	printf("%d", dirt_sum);
}