// 2468 안전 영역
// https://www.acmicpc.net/problem/2468
#include <stdio.h>

int island[100][100];
int visited[100][100] = {0, };
int N, min = 999, max = 0;
int max_area = -1, area;

void DFS(int y, int x, int height){
	visited[y][x] = -1;
	if (y > 0 && visited[y - 1][x] == 0 && island[y - 1][x] > height){
		DFS(y - 1, x, height);
	}
	if (y < N - 1 && visited[y + 1][x] == 0 && island[y + 1][x] > height){
		DFS(y + 1, x, height);
	}
	if (x > 0 && visited[y][x - 1] == 0 && island[y][x - 1] > height){
		DFS(y, x - 1, height);
	}
	if (x < N - 1 && visited[y][x + 1] == 0 && island[y][x + 1] > height){
		DFS(y, x + 1, height);
	}
	return;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &island[i][j]);
			if (max < island[i][j]){max = island[i][j];}
			if (min > island[i][j]){min = island[i][j];}
		}
	}
	for (int x = min - 1; x <= max; x++){
		area = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (island[i][j] > x && visited[i][j] == 0){ // 안 잠기는 지역
					DFS(i, j, x);
					area++;
				}
				else {visited[i][j] = -1;}
			}
		}
		if (max_area < area) {max_area = area;}
	}
	printf("%d", max_area);
}