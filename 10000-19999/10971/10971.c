// 10971 외판원 순회 2
// https://www.acmicpc.net/problem/10971
#include <stdio.h>
#define INF 123456789

int DP[65536][10] = {0, };
int arr[10][10] = {0, };
int N;

int TSP(int visit, int city){// visit: 지금까지 방문한 도시 집합
	int temp;
	visit |= (1 << city);
	if (visit == (1 << N) - 1){
		if (arr[city][0] > 0){return arr[city][0];} // 마지막 도시에서 돌아갈 수 있을 때
		else {return INF;}
	}
	if (DP[visit][city] > 0){return DP[visit][city];} // 이미 해당 경로의 최솟값이 존재한다면
	DP[visit][city] = INF;
	for (int i = 0; i < N; i++){
		if (i != city && arr[city][i] != 0 && (visit & (1 << i)) == 0){ // 같은 도시가 아니고, 길이 존재하며, 아직 방문하지 않은 도시일 때
			temp = TSP(visit, i) + arr[city][i];
			if (DP[visit][city] > temp){
				DP[visit][city] = temp;
			}
		}
	}
	return DP[visit][city];
}

int main(){
	int answer;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	answer = TSP(0, 0);
	if (answer == INF){printf("-1");}
	else {printf("%d", answer);}
}