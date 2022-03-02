// 2530 인공지능 시계
// https://www.acmicpc.net/problem/2530
#include <stdio.h>

int main(){
	int hour, min, second, time;
	scanf("%d %d %d", &hour, &min, &second);
	scanf("%d", &time);
	second += time;
	min += second / 60;
	second %= 60;
	hour += min / 60;
	min %= 60;
	hour %= 24;
	printf("%d %d %d", hour, min, second);
}