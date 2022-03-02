// 1236 성 지키기
// https://www.acmicpc.net/problem/1236
#include <stdio.h>

char castle[51][51];
int x_visited[51] = {0, };
int y_visited[51] = {0, };

int main(){
	int Y, X, answer;
	int Y_count = 0, X_count = 0;
	scanf("%d %d", &Y, &X);
	for (int y = 0; y < Y; y++){
		scanf("%s", castle[y]);
	}
	for (int y = 0; y < Y; y++){
		for (int x = 0; x < X; x++){
			if (castle[y][x] == 'X'){
				if (x_visited[x] == 0){
					X_count++;
					x_visited[x] = 1;
				}
				if (y_visited[y] == 0){
					Y_count++;
					y_visited[y] = 1;
				}
			}
		}
	}
	answer = X - X_count > Y - Y_count ? X - X_count : Y - Y_count;
	printf("%d", answer);
}