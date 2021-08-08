// 1912 연속합
// 뭔가 부족한데...
#include <stdio.h>

int arr[100001] = {0, };
int dp[100001] = {0, };
int max = -1000000000;

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	if (max < arr[0]) {max = arr[0];}
	for (int i = 1; i < N; i++){
		if (dp[i - 1] < 0){
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}
		if (max < dp[i]){
			max = dp[i];
		}
	}
	printf("%d", max);
}