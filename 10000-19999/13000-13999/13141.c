// 13141 Ignition
// https://www.acmicpc.net/problem/13141
// double 함부로 건드리지 마라
#include <stdio.h>

int Graph[201][201];
int max_len[201][201] = {0, };
int INF = 987654321;
int N, M;

void FLOYD_WARSHALL(int n){
	for (int k = 1; k <= n; k++){
		for (int start = 1; start <= n; start++){
			for (int end = 1; end <= n; end++){
				if (Graph[start][end] > Graph[start][k] + Graph[k][end]){
					Graph[start][end] = Graph[start][k] + Graph[k][end];
				}
			}
		}
	}
	return;
}

int main(){
	int S, E, edge_string;
	double L, answer = INF, time, cur_max, remain_string;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i != j){Graph[i][j] = INF;}
			max_len[i][j] = -1;
		}
	}
	for (int m = 0; m < M; m++){
		scanf("%d %d %lf", &S, &E, &L);
		if (Graph[S][E] == INF || Graph[S][E] > L){
			Graph[S][E] = L; Graph[E][S] = L;
		}
		if (max_len[S][E] == -1 || max_len[S][E] < L){
			max_len[S][E] = L; max_len[E][S] = L;
		}
	}
	FLOYD_WARSHALL(N);
	for (int start = 1; start <= N; start++){
		cur_max = 0.0;
		for (int EdgeA = 1; EdgeA <= N; EdgeA++){
			for (int EdgeB = 1; EdgeB <= N; EdgeB++){
				edge_string = max_len[EdgeA][EdgeB];
				if (edge_string != -1){ // 두 정점을 잇는 선이 존재할 때
					remain_string = max_len[EdgeA][EdgeB] - (Graph[start][EdgeB] - Graph[start][EdgeA]);
					// start에서 태우기 시작한 후, EdgeA와 EdgeB 둘 다 불이 붙었을 때 둘을 잇는 선의 남은 부분
					if (remain_string > 0){ // 남았다면
						time = Graph[start][EdgeB] + (remain_string / 2); // 양쪽 끝이 불타기 시작하기까지의 시간 + 남은 줄이 다 타기까지의 시간
						if (time > cur_max){cur_max = time;} // 가장 오래 걸리는 사이클을 구하기 위함
					}
				}
				
			}
		}
		if (answer > cur_max){answer = cur_max;} // 아무리 오래 걸려도 현재까지의 최솟값보다 짧게 걸릴 때
	}
	printf("%.1lf", answer);
}