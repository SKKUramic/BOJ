// 14938 서강그라운드
// https://www.acmicpc.net/problem/14938
#include <stdio.h>
#define INF 99999999;

int Graph[101][101] = {0, };
int item[101];

void Floyd_Warshall(int n){
	for (int waypoint = 1; waypoint <= n; waypoint++){
		for (int start = 1; start <= n; start++){
			for (int end = 1; end <= n; end++){
				if (Graph[start][waypoint] + Graph[waypoint][end] < Graph[start][end]){
					Graph[start][end] = Graph[start][waypoint] + Graph[waypoint][end];
				}
			}
		}
	}
	return;
}

int Find_maxitem(int start, int max, int limit, int n){
	int ret = 0;
	for (int end = 1; end <= n; end++){
		if (Graph[start][end] <= limit){
			ret += item[end];
		}
	}
	return max > ret ? max : ret;
}

int main(){
	int N, M, R, start, end, time, max = -1;
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			if (i != j){Graph[i][j] = INF;}
		}
	}
	scanf("%d %d %d", &N, &M, &R);
	for (int n = 1; n <= N; n++){
		scanf("%d", &item[n]);
	}
	for (int r = 0; r < R; r++){
		scanf("%d %d %d", &start, &end, &time);
		Graph[start][end] = time;
		Graph[end][start] = time;
	}
	Floyd_Warshall(N);
	for (int i = 1; i <= N; i++){
		max = Find_maxitem(i, max, M, N);
	}
	printf("%d", max);
}