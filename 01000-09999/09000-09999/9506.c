// 9506 약수들의 합
// https://www.acmicpc.net/problem/9506
#include <stdio.h>

int arr[10000];

int main(){
	int N, sum, idx;
	scanf("%d", &N);
	while (N != -1){
		sum = 0, idx = 0;
		for (int i = 1; i <= N / 2; i++){
			if (N % i == 0){
				sum += i;
				arr[idx++] = i;
			}
		}
		if (sum == N){
			printf("%d = ", N);
			for (int i = 0; i < idx; i++){
				if (i == idx - 1){
					printf("%d\n", arr[i]);
				}
				else {
					printf("%d + ", arr[i]);
				}
				
			}
		}
		else {
			printf("%d is NOT perfect.\n", N);
		}
		scanf("%d", &N);
	}
}