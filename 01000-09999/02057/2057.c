// 2057 팩토리얼 분해
// https://www.acmicpc.net/problem/2057
#include <stdio.h>

long long factorial[21];

int main(){
	long long N;
	factorial[0] = 1; factorial[1] = 1;
	for (long long i = 2; i <= 20; i++){
		factorial[i] = factorial[i - 1] * i;
	}
	scanf("%lld", &N);
	if (N == 0){
		printf("NO");
		return 0;
	}
	for (int i = 20; i >= 0; i--){
		if (factorial[i] <= N){N -= factorial[i];}
	}
	if (N){printf("NO");}
	else {printf("YES");}
}