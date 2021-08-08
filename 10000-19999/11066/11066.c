// 11066 파일 합치기
// https://www.acmicpc.net/problem/11066
// knuth's optimization을 사용하면 쉽게 풀리는 문제입니다. 놀랍게도 파일 합치기 2도 이 방법으로 풀립니다.
#include <stdio.h>

long long int dp[501][501] = {0, }; // dp[a][b] = a장부터 b장까지의 최솟값, a == b면 0
long long int arr[501]; // 그냥 다 저장함
long long int sum[501] = {0, }; // 1장부터 x장까지의 합 (0장은 없음)

long long int min(long long int a, long long int b){ //0은 안 됨
	if (a == 0) {return b;}
	return a < b ? a : b;
}

void init(int N){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			dp[j][i] = 0;
		}
	}
	return;
}

int main(){
	int T, chapter;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &chapter);
		init(chapter);
		for (int i = 1; i <= chapter; i++){
			scanf("%lld", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}
		if (chapter == 1) { // 1장짜리 소설ㄷㄷ
			printf("%lld\n", sum[1]);
			continue;
		}
		for (int interval = 1; interval <= chapter - 1; interval++){
			for (int start = 1; start <= chapter - interval; start++){
				int end = start + interval;
				for (int middle = start; middle < end; middle++){
					dp[start][end] = min(dp[start][end], dp[start][middle] + dp[middle + 1][end] + (sum[end] - sum[start - 1]));
					// 현재 값(0 아님) VS (start장부터 middle장까지의 합 중 최솟값) + (middle + 1장부터 end장까지의 합 중 최솟값) + (start장부터 end장까지의 각 장의 합)
					// 현재 값이 0이면 후자가 반드시 확정됨(후자가 0일 리는 없음)
				}
			}
		}
		printf("%lld\n", dp[1][chapter]);
	}
}