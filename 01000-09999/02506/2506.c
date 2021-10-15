// 2506 점수계산
// https://www.acmicpc.net/problem/2506
#include <stdio.h>

int main(){
	int arr[101] = {0, };
	int N, sum = 0, score = 0;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	for (int n = 0; n < N; n++){
		if (arr[n] == 1){
			sum += ++score;
		}
		else {
			score = 0;
		}
	}
	printf("%d", sum);
}