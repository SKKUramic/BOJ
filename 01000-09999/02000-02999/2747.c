// 2747 피보나치 수
#include <stdio.h>

int fibonacci[100] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	fibonacci[1] = 1;
	for (int i = 2; i <= N; i++){
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	printf("%d", fibonacci[N]);
}