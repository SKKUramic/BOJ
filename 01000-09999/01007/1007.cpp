// 1007 벡터 매칭
// https://www.acmicpc.net/problem/1007
#include <iostream>
#include <cmath>
#define INF 999999999.0
using namespace std;

int T, N;
double answer;
double point[21][2];
bool visited[21];

void match_vector(int plus, int idx, double sum_x, double sum_y){
	visited[idx] = true;
	sum_x += point[idx][0];	sum_y += point[idx][1];
	if ((idx == N - 1 && plus < N / 2) || (plus > N / 2)){
		visited[idx] = false;
		return;
	}
	if (plus == N / 2){
		for (int i = 0; i < N; i++){
			if (visited[i] == false){
				sum_x -= point[i][0];
				sum_y -= point[i][1];
			}
		}
		if (answer * answer > sum_x * sum_x + sum_y * sum_y){
			answer = sqrt(sum_x * sum_x + sum_y * sum_y);
		}
		visited[idx] = false;
		return;
	}
	for (int i = idx + 1; i < N; i++){
		match_vector(plus + 1, i, sum_x, sum_y);
	}
	visited[idx] = false;
	return;
}

int main(){
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		answer = INF;
		for (int i = 0; i < N; i++){
			scanf("%lf %lf", &point[i][0], &point[i][1]);
		}
		for (int i = 0; i < N; i++){
			match_vector(1, i, 0.0, 0.0);
		}
		printf("%.12lf\n", answer);
	}
}