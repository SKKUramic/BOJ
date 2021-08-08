// 2750 수 정렬하기
#include <stdio.h>

int arr[1001];

int main(){
	int N, temp;
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < N; i++){
		temp = arr[i];
		for (j = i - 1; j >= 0; j--){
			if (arr[j] > temp){
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp;
	}
	for (i = 0; i < N; i++){
		printf("%d\n", arr[i]);
	}
}