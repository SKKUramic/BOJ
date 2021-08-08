// 12865 평범한 배낭
// https://www.acmicpc.net/problem/12865
// knapsack 알고리즘을 사용하는 문제
#include <stdio.h>

int N, limit_weight;
int Knapsack[101][100001] = {0, };
int weight[101];
int value[101];

void print(){
	for (int i = 0; i <= N + 1; i++){
		for (int j = 0; j <= limit_weight + 1; j++){
			printf("%d ", Knapsack[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(){
	int vi, wi;
	scanf("%d %d", &N, &limit_weight);
	for (int i = 1; i <= N; i++){
		scanf("%d %d", &weight[i], &value[i]);
	}
	for (int i = 1; i <= N; i++){
		wi = weight[i];
		vi = value[i];
		for (int w = 1; w <= limit_weight; w++){
			if (wi > w){
				Knapsack[i][w] = Knapsack[i - 1][w];
			}
			else {
				Knapsack[i][w] = (vi + Knapsack[i - 1][w - wi]) > Knapsack[i - 1][w] ? (vi + Knapsack[i - 1][w - wi]) : Knapsack[i - 1][w];
			}
		}
	}
	//print();
	printf("%d", Knapsack[N][limit_weight]);
	return 0;
}