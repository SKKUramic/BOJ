// 1731 추론
// https://www.acmicpc.net/problem/1731
#include <stdio.h>

int arr[51] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	if (arr[0] == arr[1]){printf("%d", arr[0]);}
	else if (arr[1] - arr[0] == arr[2] - arr[1]){
		printf("%d", arr[N - 1] + (arr[1] - arr[0]));
	}
	else {
		printf("%d", arr[N - 1] * (arr[1] / arr[0]));
	}
}