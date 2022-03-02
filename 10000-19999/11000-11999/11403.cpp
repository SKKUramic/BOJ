// 11403 경로 찾기
// https://www.acmicpc.net/problem/11403
#include <iostream>

int Graph[100][100] = {0, };

void Floyd_Warshall(int n){
	for (int k = 0; k < n; k++){
		for (int start = 0; start < n; start++){
			for (int end = 0; end < n; end++){
				if (Graph[start][k] == 1 && Graph[k][end] == 1){
					Graph[start][end] = 1;
				}
			}
		}
	}
	return;
}

int main(){
	bool count_flags;
	int N, count_up, pop_count;
	int x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &Graph[i][j]);
		}
	}
	Floyd_Warshall(N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}