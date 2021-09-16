// 16173 점프왕 쩰리 (Small)
// https://www.acmicpc.net/problem/16173
#include <stdio.h>

int CanGo[65][65] = {0, };
int map[65][65] = {0, };
int N, flag = 0;

void DFS(int y, int x){
	if (CanGo[y][x] == 1 || flag == 1){return;}
	CanGo[y][x] = 1;
	if (map[y][x] == -1){
		flag = 1;
		return;
	}
	if (y + map[y][x] <= N){
		DFS(y + map[y][x], x);
	}
	if (x + map[y][x] <= N){
		DFS(y, x + map[y][x]);
	}
	return;
}

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	DFS(1, 1);
	if (flag == 1){printf("HaruHaru");}
	else {printf("Hing");}
}