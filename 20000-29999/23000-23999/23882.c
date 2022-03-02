// 23882 알고리즘 수업 - 선택 정렬 2
// https://www.acmicpc.net/problem/23882
#include <stdio.h>

int arr[10001];

int main(){
	int N, K, change = 0;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	for (int n = 0; n < N; n++){
		int max = -1;
		int idx;
		for (int k = 0; k < N - n; k++){
			if (max < arr[k]){
				max = arr[k];
				idx = k;
			}
		}
		if (idx == N - 1 - n){continue;}
		int temp = arr[idx];
		arr[idx] = arr[N - 1 - n];
		arr[N - 1 - n] = temp;
		change++;
		if (change == K){
			for (int i = 0; i < N; i++){
				printf("%d ", arr[i]);
			}
			return 0;
		}
	}
	printf("-1");
}