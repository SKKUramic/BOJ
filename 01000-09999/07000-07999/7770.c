// 7770 아즈텍 피라미드
// https://www.acmicpc.net/problem/7770
#include <stdio.h>

int main(){
	long long n, ans = 0, block = 0;
	scanf("%lld", &n);
	while (block <= n){
		block += (2 * ans * (ans + 1) + 1);
		ans++;
	}
	printf("%lld", ans - 1);
}