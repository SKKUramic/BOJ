// 1267 핸드폰 요금
// https://www.acmicpc.net/problem/1267
#include <stdio.h>

int main(){
	int Y_cost = 0, M_cost = 0, T, time;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &time);
		Y_cost += (1 + time / 30) * 10;
		M_cost += (1 + time / 60) * 15;
	}
	if (Y_cost > M_cost){
		printf("M %d", M_cost);
	}
	else if (Y_cost < M_cost){
		printf("Y %d", Y_cost);
	}
	else {
		printf("Y M %d", Y_cost);
	}
}