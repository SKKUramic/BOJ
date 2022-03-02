// 11020 점프 점프
// https://www.acmicpc.net/problem/11060
#include <stdio.h>

int arr[1001] = {0, };
int DP[1105] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		DP[i] = 999999;
	}
	DP[0] = 0;
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j <= i + arr[i]; j++){
			if (DP[j] > DP[i] + 1){
				DP[j] = DP[i] + 1;
			}
		}
	}
	if (DP[N - 1] == 999999){printf("-1");}
	else {printf("%d", DP[N - 1]);}
}