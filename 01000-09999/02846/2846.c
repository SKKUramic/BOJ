// 2846 오르막길
// https://www.acmicpc.net/problem/2846
#include <stdio.h>

int arr[1001] = {0, };

int main(){
	int N, idx = 0, max = 0, temp_idx;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	while (idx < N){
		if (idx == N - 1){break;}
		if (arr[idx] < arr[idx + 1]){
			temp_idx = idx + 1;
			while (arr[temp_idx] < arr[temp_idx + 1]){temp_idx++;}
			if (max < arr[temp_idx] - arr[idx]){max = arr[temp_idx] - arr[idx];}
			idx = temp_idx;
		}
		else {idx++;}
	}
	printf("%d", max);
}