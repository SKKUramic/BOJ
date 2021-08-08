// 16486 운동장 한 바퀴
// https://www.acmicpc.net/problem/16486
#include <stdio.h>
#define PI 3.141592

int main(){
	double d1, r;
	scanf("%lf %lf", &d1, &r);
	printf("%lf", 2.0000000000 * PI * r + 2.000000000000 * d1);
}