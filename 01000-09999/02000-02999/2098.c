// 2098 외판원 순회
// https://www.acmicpc.net/problem/2098
// https://withhamit.tistory.com/246(햄과 함께님의 블로그)에서 많이 배웠습니다
#include <stdio.h>
#define INF 123456789

int DP[65536][16] = {0, };
int arr[16][16] = {0, };
int N;

int TSP(int visit, int city){// visit: 지금까지 방문한 도시 집합
	int temp;
	visit |= (1 << city);
	if (visit == (1 << N) - 1){
		if (arr[city][0] > 0){return arr[city][0];}
		else {return INF;}
	}
	if (DP[visit][city] > 0){return DP[visit][city];}
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