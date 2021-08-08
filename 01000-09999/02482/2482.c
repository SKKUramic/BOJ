// 2482 색상환
// https://www.acmicpc.net/problem/2482
#include <stdio.h>
#define MOD 1000000003

long long color[1001][1001] = {0, };

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	color[1][1] = 1; color[2][1] = 2; color[3][1] = 3; // 기저 사례
	for (int n = 4; n <= N; n++){
		for (int k = 1; k <= n / 2; k++){ // n: 총 색깔 개수, k: 선택한 색깔 개수
			if (k == 1){color[n][k] = n;}
			else {color[n][k] = (color[n - 2][k - 1] + color[n - 1][k]) % MOD;}
			// (마지막 칸에 색칠한 경우, 이때 색칠한 칸의 양옆은 반드시 색칠되지 않은 칸으로 가정된다.)+ (마지막 칸을 무조건 제외시킨 상태로 k개를 고르는 경우)
		}
	}
	printf("%lld", color[N][K]);
}