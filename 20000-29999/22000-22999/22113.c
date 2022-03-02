// 22113 창영이와 버스
// https://www.acmicpc.net/problem/22113
#include <stdio.h>

int city_bus[102][102];

int main(){
	int bus_count, bus_ride, ride_on, ride_off, money = 0;
	int bus_ride_order[102];
	scanf("%d %d", &bus_count, &bus_ride);
	for (int i = 0; i < bus_ride; i++){
		scanf("%d", &bus_ride_order[i]);
	}
	for (int a = 1; a <= bus_count; a++){
		for (int b = 1; b <= bus_count; b++){
			scanf("%d", &city_bus[a][b]);
		}
	}
	ride_on = bus_ride_order[0];
	for (int k = 1; k < bus_ride; k++){
		ride_off = bus_ride_order[k];
		money += city_bus[ride_on][ride_off];
		ride_on = ride_off;
	}
	printf("%d", money);
}