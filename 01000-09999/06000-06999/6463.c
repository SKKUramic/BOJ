// 6463 팩트
// https://www.acmicpc.net/problem/6463
#include <stdio.h>

int arr[10001] = {0, };

int main(){
	int fact, N;
	fact = 1;
	arr[0] = 1; arr[1] = 1;
	for (int i = 2; i <= 10000; i++){
		fact *= i;
		while (fact % 10 == 0){
			fact /= 10;
		}
		fact %= 100000;
		arr[i] = fact % 10;;
	}
	while (scanf("%d", &N) != EOF){
		printf("%5d -> %d\n", N, arr[N]);
	}
}