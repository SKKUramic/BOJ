// 11726 2xn 타일링
// https://www.acmicpc.net/problem/11726
// dp를 적절히 잘 쓰면 굳이 2xn 직사각형을 만들 필요가 없습니다.
#include <stdio.h>

int dp[1001] = {0, };

int main(){
	int n;
	dp[1] = 1; dp[2] = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	printf("%d", dp[n]);
}