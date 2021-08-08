// 5543 상근날드
// https://www.acmicpc.net/problem/5543
#include <stdio.h>

int main(){
	int sang_burger, jung_burger, ha_burger, cola, cider;
	int burger_min, drink_min;
	scanf("%d", &sang_burger);
	scanf("%d", &jung_burger);
	scanf("%d", &ha_burger);
	scanf("%d", &cola);
	scanf("%d", &cider);
	if (sang_burger < jung_burger){
		if (sang_burger < ha_burger){
			burger_min = sang_burger;
		}
		else {
			burger_min = ha_burger;
		}
	}
	else {
		if (jung_burger < ha_burger){
			burger_min = jung_burger;
		}
		else {
			burger_min = ha_burger;
		}
	}
	if (cola < cider){
		drink_min = cola;
	}
	else {
		drink_min = cider;
	}
	printf("%d", burger_min + drink_min - 50);
	
}