// 2417 정수 제곱근
// https://www.acmicpc.net/problem/2417
#include <stdio.h>

int main(){
	unsigned long long N, ans = 0, num;
	scanf("%llu", &N);
	for (int i = 31; i >= 0; i--){
		num = 1LL << i;
		ans += num;
		if (ans * ans > N || ans < 0){ans -= num;}
	}
	if (ans * ans < N){ans++;}
	printf("%llu", ans);
}