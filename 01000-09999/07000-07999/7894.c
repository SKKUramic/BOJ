// 7894 큰 수
// https://www.acmicpc.net/problem/7894
#include <stdio.h>
#include <math.h>

int main(){
	int N, TC;
	long double answer;
	scanf("%d", &TC);
	while (TC-- > 0){
		answer = 0.000000000000000;
		scanf("%d", &N);
		for (int n = N; n >= 2; n--){
			answer += log10((long double)n);
		}
		printf("%d\n", (int)answer + 1);
	}
}