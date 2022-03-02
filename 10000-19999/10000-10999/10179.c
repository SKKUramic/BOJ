// 10179 쿠폰
// https://www.acmicpc.net/problem/10179
#include <stdio.h>
#include <math.h>

int main(){
	int T;
	double cost;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%lf", &cost);
		cost *= 0.8;
		cost = floor(cost * 100 + 0.5) / 100;
		printf("$%.2lf\n", cost);
	}
}