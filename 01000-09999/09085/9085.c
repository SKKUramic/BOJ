// 9085 더하기
// https://www.acmicpc.net/problem/9085
#include <stdio.h>

int main(){
	int T, N, sum;
	int arr[100];
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		sum = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < N; i++){
			sum += arr[i];
		}
		printf("%d\n", sum);
	}
}