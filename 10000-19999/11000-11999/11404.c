// 11404 플로이드
// https://www.acmicpc.net/problem/11404
#include <stdio.h>

#define INF 99999999

int Graph[101][101] = {0, };

void FLOYD_WARSHALL(int CITY){
	for (int waypoint = 1; waypoint <= CITY; waypoint++){
		for (int start = 1; start <= CITY; start++){
			for (int end = 1; end <= CITY; end++){
				if (Graph[start][end] > Graph[start][waypoint] + Graph[waypoint][end]){
					Graph[start][end] = Graph[start][waypoint] + Graph[waypoint][end];
				}
			}
		}
	}
	return;
}

int main(){
	int city, bus;
	int start, end, weight;
	scanf("%d", &city);
	scanf("%d", &bus);
	for (int i = 1; i <= city; i++){
		for (int j = 1; j <= city; j++){
			if (i != j){
				Graph[i][j] = INF;	
			}
		}
	}
	for (int i = 0; i < bus; i++){
		scanf("%d %d %d", &start, &end, &weight);
		if (Graph[start][end] > weight){
			Graph[start][end] = weight;
		}
	}
	FLOYD_WARSHALL(city);
	for (int i = 1; i <= city; i++){
		for (int j = 1; j <= city; j++){
			if (Graph[i][j] == INF){
				printf("0 ");
			}
			else {
				printf("%d ", Graph[i][j]);	
			}
		}
		printf("\n");
	}
}