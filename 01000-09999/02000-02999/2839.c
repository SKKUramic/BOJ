// 2839 설탕 배달
#include <stdio.h>

int dp[5001] = {0, };

int main(){
	int kg;
	dp[3] = 1; dp[5] = 1;
	scanf("%d", &kg);
	for (int i = 6; i <= kg; i++){
		// dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1)
		if (dp[i - 3]){
			dp[i] = dp[i - 3] + 1;
		}
		if (dp[i - 5]){
			dp[i] = (dp[i]) ? (dp[i] > dp[i - 5] + 1 ? dp[i - 5] + 1 : dp[i]) : dp[i - 5] + 1;
		}
	}
	if (dp[kg] == 0){printf("-1");}
	else {
		printf("%d", dp[kg]);
	}
}