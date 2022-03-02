// 9325 얼마?
// https://www.acmicpc.net/problem/9325
#include <stdio.h>

int main(){
	int TC, car, kinds, buy, cost, cost_sum;
	scanf("%d", &TC);
	while (TC-- > 0){
		cost_sum = 0;
		scanf("%d", &car);
		cost_sum += car;
		scanf("%d", &kinds);
		for (int i = 0; i < kinds; i++){
			scanf("%d %d", &buy, &cost);
			cost_sum += buy * cost;
		}
		printf("%d\n", cost_sum);
	}
}