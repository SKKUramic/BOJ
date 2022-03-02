// 1695 팰린드롬 만들기
// https://www.acmicpc.net/problem/1695
#include <stdio.h>

int DP[5001][5001] = {0, };
int arr[5001];

int MIN(int a, int b){return a < b ? a : b;}

int main(){
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	for (int n = 0; n < N - 1; n++){
		DP[n][n + 1] = arr[n] != arr[n + 1] ? 1 : 0;
	}
	for (int step = 2; step < N; step++){
		for (int k = 0; k < N - step; k++){
			if (arr[k] == arr[k + step]){
				DP[k][k + step] = DP[k + 1][k + step - 1]; 
				// 바깥 2개는 같으므로 안쪽의 팰린드롬 필요 개수만 있으면 됨
			}
			else {
				DP[k][k + step] = MIN(DP[k + 1][k + step], DP[k][k + step - 1]) + 1;
				// 둘 중 적게 드는 것 + 1
			}
		}
	}
	printf("%d", DP[0][N - 1]);
}