// 1670 정상 회담 2
// https://www.acmicpc.net/problem/1670
#include <stdio.h>
#define REMAINDER 987654321

long long dp[5001] = {0, }; // 편의상 (꼭짓점의 개수 / 2)를 주소로 함

int main(){
	int edge;
	scanf("%d", &edge);
	edge /= 2;
	dp[1] = 1; dp[2] = 2;
	for (int e = 3; e <= edge; e++){ // 점 하나를 잡고 영역을 나눠가며 구한다
		for (int x = 0; x < e; x++){ 
			if (x == 0 || x == e - 1){
				dp[e] = (dp[e] + dp[e - 1]) % REMAINDER;
			}
			else {
				dp[e] = (dp[e] + (dp[x] * dp[e - 1 - x])) % REMAINDER;
			}
		}
	}
	printf("%lld", dp[edge] % REMAINDER);
}