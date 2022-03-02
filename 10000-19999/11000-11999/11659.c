//11659 구간 합 구하기
#include <stdio.h>

int arr[100001] = {0, };

int main(){
	int N, M, start, end;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < M; i++){
		scanf("%d %d", &start, &end);
		printf("%d\n", arr[end] - arr[start - 1]);
	}
}