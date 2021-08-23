// 2460 지능형 기차 2
// https://www.acmicpc.net/problem/2460
#include <stdio.h>

int main(){
	int train = 0, max_train = 0, ride_off, ride_on;
	for (int i = 0; i < 10; i++){
		scanf("%d %d", &ride_off, &ride_on);
		train += (ride_on - ride_off);
		if (train > max_train){max_train = train;}
	}
	printf("%d", max_train);
}