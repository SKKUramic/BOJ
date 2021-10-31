// 2010 플러그
// https://www.acmicpc.net/problem/2010
#include <stdio.h>

int main(){
	int N, answer = 1, multitap;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &multitap);
		answer += (multitap - 1);
	}
	printf("%d", answer);
}