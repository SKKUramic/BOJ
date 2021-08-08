// 2003 수들의 합 2
#include <bits/stdc++.h>

int main() {
	int N, M;
	int answer = 0;
	int X = 0;
	scanf("%d %d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int start = 0; int end = 0;
	while (start < N) {
		while (X < M && end < N) {
			X += arr[end];
			end++;
		}
		if (X == M) {
			answer++;
		}
		X -= arr[start];
		start++;
	}
	printf("%d", answer);
	free(arr);
	return 0;
}