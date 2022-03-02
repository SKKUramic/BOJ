// 10797 10부제
// https://www.acmicpc.net/problem/10797
#include <stdio.h>

int main(){
	int prohibited_day, car_num, count = 0;
	scanf("%d", &prohibited_day);
	for (int i = 0; i < 5; i++){
		scanf("%d", &car_num);
		if (car_num % 10 == prohibited_day){
			count++;
		}
	}
	printf("%d", count);
}