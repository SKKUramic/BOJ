// 10971 외판원 순회 2
// https://www.acmicpc.net/problem/10971
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double DP[65536][16] = {0, };
double arr[16][16] = {0, };
double city[16][2] = {0, };
int N;
double INF = 1234567890.0;

double TSP(int visit, int city){
	double temp;
	visit |= (1 << city);
	if (visit == (1 << N) - 1){
		if (arr[city][0] > 1e-10){return arr[city][0];}
		else {return INF;}
	}
	if (DP[visit][city] > 1e-10){return DP[visit][city];}
	DP[visit][city] = INF;
	for (int i = 0; i < N; i++){
		if (i != city && (visit & (1 << i)) == 0){ // 같은 도시가 아니고, 아직 방문하지 않은 도시일 때
			temp = TSP(visit, i) + arr[city][i];
			if (DP[visit][city] > temp){
				DP[visit][city] = temp;
			}
		}
	}
	return DP[visit][city];
}

int main(){
	double answer, x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lf %lf", &city[i][0], &city[i][1]);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i != j){
				x = fabs(city[i][0] - city[j][0]);
				y = fabs(city[i][1] - city[j][1]);
				arr[i][j] = sqrt(x * x + y * y);
			}
		}
	}
	answer = TSP(0, 0);
	printf("%.12lf", answer);
}