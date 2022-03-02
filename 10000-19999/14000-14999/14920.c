// 14920 3n+1 수열
// https://www.acmicpc.net/problem/14920
#include <stdio.h>

int main(){
	long long N, count = 1;
	scanf("%lld", &N);
	while (N != 1){
		if (N % 2){N = 3 * N + 1;}
		else {N /= 2;}
		count++;
	}
	printf("%lld", count);
}