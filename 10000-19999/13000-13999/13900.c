// 13900 순서쌍의 곱의 합
// https://www.acmicpc.net/problem/13900
#include <stdio.h>

int main(){
	long long sum = 0, answer = 0, num;
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%lld", &num);
		if (n != 0) {answer += sum * num;}
		sum += num;
	}
	printf("%lld", answer);
}