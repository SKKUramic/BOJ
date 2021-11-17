// 1740 거듭제곱
// https://www.acmicpc.net/problem/1740
#include <stdio.h>

int main(){
	long long three[41], N, answer = 0;
	scanf("%lld", &N);
	three[0] = 1;
	for (int i = 1; i < 40; i++){
		three[i] = three[i - 1] * 3;
	}
	int idx = 0;
	while (N > 0){
		if (N % 2 == 1){answer += three[idx];}
		idx++;
		N /= 2;
	}
	printf("%lld", answer);
}