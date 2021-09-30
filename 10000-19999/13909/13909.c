// 13909 창문 닫기
// https://www.acmicpc.net/problem/13909
#include <stdio.h>

int main(){
	long long N, ans = 0;
	scanf("%lld", &N);
	for (int i = 1; i * i <= N; i++){
		ans++;
	}
	printf("%lld", ans);
}