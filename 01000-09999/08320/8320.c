// 8320 직사각형을 만드는 방법
// https://www.acmicpc.net/problem/8320
#include <stdio.h>

int main(){
	long long n, ans = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		for (int j = i; i * j <= n; j++){
			ans++;
		}
	}
	printf("%lld", ans);
}