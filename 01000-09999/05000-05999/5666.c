// 5666 Hot Dogs
// https://www.acmicpc.net/problem/5666
#include <stdio.h>

int main(){
	double A, B;
	while (scanf("%lf %lf", &A, &B) != EOF){
		printf("%.2lf\n", A / B);
	}
}