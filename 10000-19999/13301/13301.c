// 13301 타일 장식물
// https://www.acmicpc.net/problem/13301
#include <stdio.h>

long long fibonacci[100] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	fibonacci[1] = 1; fibonacci[2] = 1;
	for (int i = 3; i <= N; i++){
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	printf("%lld", fibonacci[N] * 4 + fibonacci[N - 1] * 2);
}