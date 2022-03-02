// 11050 이항 계수 1
#include <stdio.h>

int factorial(int n){
	if (n == 0 || n == 1){
		return 1;
	}
	return factorial(n - 1) * n;
}

int main(){
	int N, K;
	int up, down1, down2;
	scanf("%d %d", &N, &K);
	up = factorial(N);
	down1 = factorial(K);
	down2 = factorial(N - K);
	printf("%d", up / (down1 * down2));
}