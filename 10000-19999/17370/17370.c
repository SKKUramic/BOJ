// 17370 육각형 우리 속의 개미
// https://www.acmicpc.net/problem/17370
#include <stdio.h>

int dx[6] = {1, 0, -1, -1, 0, 1};
int dy[6] = {1, 2, 1, -1, -2, -1};
int visited[200][200] = {0, }; // visited[100][100] = (0, 0)

int N, answer = 0;

void hexagon(int x, int y, int direction, int count){
	if (count == N){
		if (visited[x][y] == 1){ // 다 꺾었더니 페로몬이 있는 곳일 때
			answer++;
		}
		return;
	}
	else if (visited[x][y] == 1){ // 아직 다 안 꺾었는데 페로몬을 맡았을 때
		return;
	}
	visited[x][y] = 1;
	int next_left = (direction + 1) % 6;
	int next_right = (direction + 5) % 6;
	hexagon(x + dx[next_left], y + dy[next_left], next_left, count + 1);
	hexagon(x + dx[next_right], y + dy[next_right], next_right, count + 1);
	visited[x][y] = 0;
	return;
}

int main(){
	scanf("%d", &N);
	visited[100][100] = 1;
	hexagon(101, 101, 0, 0);
	printf("%d", answer);
}