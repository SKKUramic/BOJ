// 14730 謎紛芥索紀 (Small)
// https://www.acmicpc.net/problem/14730
#include <stdio.h>

int main(){
	int N, a, b, answer = 0;
	scanf("%d", &N);
	while (N-- > 0){
		scanf("%d %d", &a, &b);
		answer += a * b;
	}
	printf("%d", answer);
}