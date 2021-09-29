// 2501 약수 구하기
// https://www.acmicpc.net/problem/2501
#include <stdio.h>

int main(){
	int N, K, idx = 0, answer = 0;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++){
		if (N % i == 0){
			idx++;
		}
		if (idx == K){
			answer = i;
			break;
		}
	}
	printf("%d", answer);
}