// 17626 Four Squares
#include <stdio.h>
#include <math.h>

int dp[50001] = {0, };

int main(){
	int number, p = 0, temp, x, ss;
	scanf("%d", &number);
	dp[1] = 1;
	for (int i = 1; i <= number; i++){
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++){
			dp[i] = dp[i] < (1 + dp[i - j * j]) ? dp[i] : (1 + dp[i - j * j]);
		}
	}
	printf("%d", dp[number]);
}