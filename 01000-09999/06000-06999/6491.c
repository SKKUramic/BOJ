// 6491 Perfection
// https://www.acmicpc.net/problem/6491
#include <stdio.h>

int main(){
	int N, sum;
	scanf("%d", &N);
	while (N != 0){
		sum = 0;
		for (int i = 1; i <= N / 2; i++){
			if (N % i == 0){sum += i;}
		}
		if (sum == N){
			printf("%d PERFECT\n", N);
		}
		else if (sum > N){
			printf("%d ABUNDANT\n", N);
		}
		else {
			printf("%d DEFICIENT\n", N);
		}
		scanf("%d", &N);
	}
}