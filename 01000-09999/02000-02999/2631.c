// 2613 줄세우기
// https://www.acmicpc.net/problem/2631
#include <stdio.h>

int arr[201];
int LIS[201] = {0, };

int main(){
	int N;
	int min;
	int max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++){ // LIS 최대 길이만큼 이미 정렬이 되어있으므로, '전체 사람 수 - LIS 최대길이'가 답이다.
		min = 0;
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (min < LIS[j]){
					min = LIS[j];
				}
			}
		}
		LIS[i] = min + 1;
		if (max < LIS[i]){
			max = LIS[i];
		}
	}
	printf("%d", N - max);
}