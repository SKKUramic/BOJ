// 16673 고려대학교에는 공식 와인이 있다
// https://www.acmicpc.net/problem/16673
#include <stdio.h>

int main(){
	long long C, K, P, wine = 0;
	scanf("%lld %lld %lld", &C, &K, &P);
	for (int c = 1; c <= C; c++){
		wine += (K * c + P * c * c);
	}
	printf("%lld", wine);
}