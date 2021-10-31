// 2033 반올림
// https://www.acmicpc.net/problem/2033
#include <stdio.h>

int main(){
	int N, ten = 10;
	scanf("%d", &N);
	while (N > ten){
		if (N % ten >= 5 * (ten / 10)){
			N = (N - N % ten) + ten;
		}
		else {
			N -= N % ten;
		}
		ten *= 10;
	}
	printf("%d", N);
}