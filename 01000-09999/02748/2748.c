// 2748 피보나치 수 2
#include <stdio.h>

long long unsigned int fibonacci[100] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	fibonacci[1] = 1;
	for (int i = 2; i <= N; i++){
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	printf("%lld", fibonacci[N]);
}