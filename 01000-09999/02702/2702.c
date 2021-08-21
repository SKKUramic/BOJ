// 2702 초6 수학
// https://www.acmicpc.net/problem/2702
#include <stdio.h>

int GCD(int a, int b){
	return a % b ? GCD(b, a % b) : b;
}

int main(){
	int T, a, b, gcd;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d %d", &a, &b);
		if (a > b) {gcd = GCD(a, b);}
		else {gcd = GCD(b, a);}
		printf("%d %d\n", a * b / gcd, gcd);
	}
}