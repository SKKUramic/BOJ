// 3460 이진수
// https://www.acmicpc.net/problem/3460
#include <stdio.h>

int main(){
	int T, N;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		for (int i = 0; N != 0; i++){
			if (N % 2 == 1){printf("%d ", i);}
			N /= 2;
		}
		printf("\n");
	}
}