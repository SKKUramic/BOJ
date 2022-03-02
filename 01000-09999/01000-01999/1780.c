// 1780 종이의 개수
#include <stdio.h>

const int ERROR = -2;

int paper[2200][2200];
int ans[3] = {0, 0, 0};
int dx[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

int slice(int x, int y, int len){
	if (len == 1){return paper[x][y];}
	int nx, ny, color;
	int ret = paper[x][y];
	int COLOR[3] = {0, 0, 0}; // -1, 0 ,1
	for (int i = 0; i < 9; i++){
		nx = x + dx[i] * (len / 3);
		ny = y + dy[i] * (len / 3);
		color = slice(nx, ny, len / 3);
		if (color != ERROR){
			COLOR[color + 1]++;
		}
		if (ret != color){
			ret = ERROR;
		}
	}
	if (ret == ERROR){
		ans[0] += COLOR[0];
		ans[1] += COLOR[1];
		ans[2] += COLOR[2];
	}
	return ret;
}

int main(){
	int N, first_color;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &paper[i][j]);
		}
	}
	first_color = slice(0, 0, N);
	if (first_color != ERROR){
		ans[first_color + 1]++;
	}
	/*
	printf("============\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", paper[i][j]);
		}
		printf("\n");
	}
	printf("============\n");
	*/
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}