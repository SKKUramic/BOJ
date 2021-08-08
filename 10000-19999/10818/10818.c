// 10818 최소, 최대
#include <stdio.h>

int main(int argc, char* argv[]) {
	int arr[1000000];
	int N, max = -1000001, min = 1000001;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++){
		if (max < arr[i]){
			max = arr[i];
		}
		if (min > arr[i]){
			min = arr[i];
		}
	}
	printf("%d %d", min, max);
}