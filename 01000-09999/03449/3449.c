// 3449 해밍 거리
// https://www.acmicpc.net/problem/3449
#include <stdio.h>
#include <string.h>

int main(){
	int TC, len, hamming;
	char A[101], B[101];
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%s", A);
		scanf("%s", B);
		len = strlen(A);
		hamming = 0;
		for (int i = 0; i < len; i++){
			if (A[i] != B[i]){hamming++;}
		}
		printf("Hamming distance is %d.\n", hamming);
	}
}