// 4998 저금
// https://www.acmicpc.net/problem/4998
#include <stdio.h>

int main(){
	int count;
	double money, r, M;
	while (scanf("%lf %lf %lf", &money, &r, &M) != EOF){
		count = 0;
		r /= 100.0000000000;
		r += 1.000000000000;
		while (money - M < -0.000001){
			money *= r;
			count++;
		}
		printf("%d\n", count);
	}
}