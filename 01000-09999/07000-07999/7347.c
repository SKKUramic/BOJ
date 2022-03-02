// 7347 플립과 시프트
// https://www.acmicpc.net/problem/7347
#include <stdio.h>
#include <string.h>

int sequence[32];

int main(){
	int TC, N, B, odd, even;
	int flag, idx;
	scanf("%d", &TC);
	while (TC-- > 0){
		memset(sequence, -1, 32 * sizeof(int));
		scanf("%d", &N);
		B = 0; odd = 0; even = 0;
		for (int n = 0; n < N; n++){
			scanf("%d", &sequence[n]);
			if (sequence[n] == 0){
				if (n % 2 == 0){even++;}
				else {odd++;}
			}
		}
		if (N % 2 == 1){printf("YES\n");} // 검은 돌들을 자유자재로 옮길 수 있음
		else { // 홀수 idx에 있는 구슬은 홀수 idx에서만, 짝수는 짝수 idx에서만 움직일 수 있음
			if (-1 <= odd - even && odd - even <= 1){ // 둘이 하나 이하 차이여야지만 일렬로 정렬 가능
				printf("YES\n");
			}
			else { // 아무리 일렬로 정렬해도 끊기는 부분이 있음
				printf("NO\n");
			}
		}
	}
}