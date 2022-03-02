// 1992 쿼드트리
#include <stdio.h>
#include <stdbool.h>

char video[64][64];
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};


void video_compression(int x, int y, int len){
	if (len == 1){
		printf("%c", video[x][y]);
		return;
	}
	bool ZERO = true, ONE = true;
	int nx, ny;
	int zero_or_one[4] = {0, }; // 0 = 0, 1 = true, -1 = mix
	for (int i = x; i < x + len; i++){
		for (int j = y; j < y + len; j++){
			if (video[i][j] == '0'){ONE = false;}
			else if (video[i][j] == '1'){ZERO = false;}
		}
	}
	if (ZERO == true){
		printf("0");
		return;
	}
	else if (ONE == true){
		printf("1");
		return;
	}
	else {
		printf("(");
		for (int i = 0; i < 4; i++){
			nx = x + dx[i] * (len / 2);
			ny = y + dy[i] * (len / 2);
			video_compression(nx, ny, len / 2);
		}
		printf(")");
		return;
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", video[i]);
	}
	video_compression(0, 0, N);
	return 0;
}