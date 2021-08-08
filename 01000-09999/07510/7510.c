// 7510 고급 수학
// https://www.acmicpc.net/problem/7510
#include <stdio.h>

int main(){
	int T;
	long long a, b, c;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Scenario #%d:\n", i);
		if (a * a == b * b + c * c || a * a + c * c == b * b || a * a + b * b == c * c){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		if (i != T){printf("\n");}
	}
}