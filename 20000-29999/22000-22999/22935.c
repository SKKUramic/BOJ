// 22935 이진 딸기
// https://www.acmicpc.net/problem/22935
#include <stdio.h>

int arr[4];

int main(){
	int N, TC;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &N);
		N %= 28;
		if (N == 0){N += 28;}
		if (N > 15){N = 15 - (N - 15);}
		for (int i = 0; i < 4; i++){
			arr[i] = N % 2;
			N /= 2;
		}
		for (int i = 3; i >= 0; i--){
			if (arr[i] == 1){printf("딸기");}
			else {printf("V");}
		}
		printf("\n");
	}
}