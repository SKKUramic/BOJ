// 11966 2의 제곱인가?
// https://www.acmicpc.net/problem/11966
#include <stdio.h>

int main(){
	long long N;
	scanf("%lld", &N);
	while (N != 1){
		if (N % 2 == 1){
			printf("0");
			return 0;
		}
		N /= 2;
	}
	printf("1");
}