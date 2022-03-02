// 2862 수학 게임
// https://www.acmicpc.net/problem/2862
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
	FIBONACCI_len = idx; // 여기까지
	while (1){
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
// 1 2 3 1 5 1 2 8 1 2 3 1 13
// 피보나치 수열이 반복된다