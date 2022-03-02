// 5361 전투 드로이드 가격
// https://www.acmicpc.net/problem/5361
#include <stdio.h>

const double cost[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
double arr[5];

int main(){
	int N;
	double sum;
	scanf("%d", &N);
	while (N-- > 0){
		sum = 0;
		for (int i = 0; i < 5; i++){
			scanf("%lf", &arr[i]);
			sum += arr[i] * cost[i];
		}
		printf("$%.2lf\n", sum);
	}
}