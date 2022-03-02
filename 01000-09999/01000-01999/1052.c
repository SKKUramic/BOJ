// 1052 물병
// https://www.acmicpc.net/problem/1052
#include <stdio.h>

int main(){
	long long N, K, temp, answer = 0, one_cnt;
	scanf("%lld %lld", &N, &K);
	if (N <= K){ // N보다 K가 크면 확인할 필요가 없다
		printf("0");
		return 0;
	}
	for (; ; answer++){
		one_cnt = 0;
		temp = N;
		while (temp){
			if (temp % 2 == 1){one_cnt++;}
			temp /= 2;
		}
		if (one_cnt <= K){break;} // 물병이 충분히 존재할 경우
		N++;
	}
	printf("%lld", answer);
}