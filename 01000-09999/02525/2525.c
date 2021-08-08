// 2525 오븐 시계
// https://www.acmicpc.net/problem/2525
#include <stdio.h>

int main(){
	int hour, min, time, count_up = 0;
	scanf("%d %d", &hour, &min);
	scanf("%d", &time);
	min += time;
	while (min >= 60){
		min -= 60;
		count_up++;
	}
	hour = (hour + count_up) % 24;
	printf("%d %d", hour, min);
}