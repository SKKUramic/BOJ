// 1817 짐 챙기는 숌
// https://www.acmicpc.net/problem/1817
#include <stdio.h>

int arr[100000];

int main(){
	int N, M, BOX_weight = 0, BOX_count = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++){
		if (BOX_weight + arr[i] > M){
			BOX_count++;
			BOX_weight = arr[i];
		}
		else {
			BOX_weight += arr[i];
		}
	}
	if (BOX_weight != 0){BOX_count++;}
	printf("%d", BOX_count);
}