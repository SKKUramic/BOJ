// 14264 정육각형과 삼각형
// https://www.acmicpc.net/problem/14264
#include <stdio.h>
#include <math.h>

int main(){
	double s;
	scanf("%lf", &s);
	printf("%.15lf", sqrt(3) * s * s / 4);
}