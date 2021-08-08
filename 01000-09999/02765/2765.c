// 2765 자전거 속도
// https://www.acmicpc.net/problem/2765
// 1마일 = 5280피트, 1피트 = 12인치, 1펄롱 = 201.168미터 = 1/8마일 = 660마일
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(){
	int count = 1;
	double diameter, revolutions, time, miles, miles_per_hour;
	scanf("%lf %lf %lf", &diameter, &revolutions, &time);
	while (revolutions >= 0.000001){
		miles = (diameter * revolutions) * PI / (63360);
		miles_per_hour = miles * (3600 / time);
		miles = floor(miles * 100 + 0.5) / 100;
		miles_per_hour = floor(miles_per_hour * 100 + 0.5) / 100;
		printf("Trip #%d: %.2lf %.2lf\n", count, miles, miles_per_hour);
		scanf("%lf %lf %lf", &diameter, &revolutions, &time);
		count++;
	}
}