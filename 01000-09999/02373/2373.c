// 2373 Fibonacci Game
// https://www.acmicpc.net/problem/2373
// 2862 수학 게임과 풀이가 사실상 같은 문제
#include <stdio.h>

long long FIBONACCI[100] = {0, };

int main(){
	int idx = 3, FIBONACCI_len;
	long long N;
	scanf("%lld", &N);
	FIBONACCI[1] = 1; FIBONACCI[2] = 1;
	while (1){
		if (FIBONACCI[idx - 2] + FIBONACCI[idx - 1] <= 1e+15){
			FIBONACCI[idx] = FIBONACCI[idx - 2] + FIBONACCI[idx - 1];
		}
		else {break;}
		idx++;
	}
	FIBONACCI_len = idx;
	for (int i = 0; i < FIBONACCI_len; i++){ // 여기서 걸리면 무슨 수를 써도 선공이 패배한다
		if (FIBONACCI[i] == N){
			printf("-1");
			return 0;
		}
	}
	while (1){ // 일단 선공이 이길 수 있는 수가 있다
		for (int i = 0; i < FIBONACCI_len; i++){
			if (FIBONACCI[i] == N){
				printf("%lld", FIBONACCI[i]);
				return 0;
			}
			if (FIBONACCI[i] > N){
				N -= FIBONACCI[i - 1];
				break;
			}
			if (i == FIBONACCI_len - 1 && FIBONACCI[i] < N){
				N -= FIBONACCI[i];
			}
		}
	}
}