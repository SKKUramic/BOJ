// 1138 한 줄로 서기
// https://www.acmicpc.net/problem/1138
#include <stdio.h>

int main(){
	int arr[10] = {0, };
	int order[10] = {0, };
	int N, idx;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &order[i]);
	}
	for (int i = 0; i < N; i++){
		idx = 0;
		for (int j = 0; j < N; j++){
			if (idx == order[i] && arr[j] == 0){
				arr[j] = i + 1;
				break;
			}
			if (arr[j] == 0){idx++;}
		}
	}
	for (int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
}