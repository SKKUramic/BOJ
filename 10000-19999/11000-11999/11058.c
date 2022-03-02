// 11058 크리보드
// https://www.acmicpc.net/problem/11058
#include <stdio.h>

long long dp[101] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	dp[1] = 1; dp[2] = 2; dp[3] = 3; // 3번까지는 무슨 짓을 해도 그냥 A를 입력하는 게 이득임
	for (int n = 4; n <= N; n++){
		dp[n] = n; // 그냥 A 버튼만 눌렀을 때
		for (int cv = 1; cv <= n - 3; cv++){
			if (dp[cv] + dp[cv] * (n - 2 - cv) > dp[n]){ // dp[n]보다 dp[cv] + dp[cv] * (Ctrl+V를 누른 횟수)가 더 클 때
				dp[n] = dp[cv] + dp[cv] * (n - 2 - cv);
			}
		}
	}
	printf("%lld", dp[N]);
}