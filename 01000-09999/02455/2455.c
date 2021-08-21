// 2455 지능형 기차
// https://www.acmicpc.net/problem/2455
#include <stdio.h>

int main(){
	int ride_on, ride_off, max_ride = -1, ride_now = 0;
	for (int i = 0; i < 4; i++){
		scanf("%d %d", &ride_off, &ride_on);
		ride_now = ride_now + ride_on - ride_off;
		if (ride_now > max_ride){max_ride = ride_now;}
	}
	printf("%d", max_ride);
}