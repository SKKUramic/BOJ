// 23881 알고리즘 수업 - 선택 정렬 1
// https://www.acmicpc.net/problem/23881
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
			printf("%d %d", arr[idx], arr[N - 1 - n]);
			return 0;
		}
	}
	printf("-1");
}