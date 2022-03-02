// 15729 방탈출
// https://www.acmicpc.net/problem/15729
#include <stdio.h>

int light[1000010];
int current[1000010] = {0, };

int main(){
	int N, count = 0;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &light[n]);
	}
	for (int n = 0; n < N; n++){
		if (current[n] != light[n]){
			current[n] ^= 1;
			current[n + 1] ^= 1;
			current[n + 2] ^= 1;
			count++;
		}
	}
	printf("%d", count);
}