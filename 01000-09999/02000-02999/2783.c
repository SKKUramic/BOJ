// 2783 삼각 김밥
// https://www.acmicpc.net/problem/2783
#include <stdio.h>

double cost_per_gram;

int main(){
	int TC;
	double a, b;
	scanf("%lf %lf", &a, &b);
	cost_per_gram = b / a;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%lf %lf", &a, &b);
		if (cost_per_gram < b / a){
			cost_per_gram = b / a;
		}
	}
	printf("%.2lf", 1000.0 / cost_per_gram);
}