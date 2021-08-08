// 21633 Bank Transfer
// https://www.acmicpc.net/problem/21633
#include <stdio.h>

#define EPSILON 0.00000001

int main(){
	double k, commission;
	scanf("%lf", &k);
	commission = 25 + k * 0.01;
	if (commission < 100 + EPSILON){commission = 100;}
	else if (commission > 2000 - EPSILON) {commission = 2000;}
	printf("%.2lf", commission);
	
}