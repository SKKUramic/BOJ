// 4766 일반 화학 시험
// https://www.acmicpc.net/problem/4766
#include <stdio.h>

int main(){
	double prev, cur;
	scanf("%lf", &prev);
	while (1){
		scanf("%lf", &cur);
		if (cur - 998.9999999 > 1e-8){break;}
		printf("%.2lf\n", cur - prev);
		prev = cur;
	}
}