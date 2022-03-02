// 11062 카드 게임
// https://www.acmicpc.net/problem/11062
#include <stdio.h>
#include <string.h>

int DP[1001][1001];
int arr[1001];

int three_return(int a, int b, int c){
	if (a < b){
		if (a < c){return a;}
		else {return c;}
	}
	else {
		if (b < c){return b;}
		else {return c;}
	}
}

int MIN(int a, int b){return a < b ? a : b;}
int MAX(int a, int b){return a > b ? a : b;}

int main(){
	int T, N;
	scanf("%d", &T);
	while (T-- > 0){
		int score = 0, turn = 1;
		scanf("%d", &N);
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < N; i++){
			DP[i][i] = (N % 2) ? arr[i] : 0;
		}
		for (int step = 1; step < N; step++){
			for (int k = 0; k < N - step; k++){
				if ((N - step) % 2){ // 근우가 선택하는 턴일 경우
					DP[k][k + step] = MAX(DP[k + 1][k + step] + arr[k], DP[k][k + step - 1] + arr[k + step]);
					// 근우가 선택하는 턴이므로 근우가 이익을 최대로 보는 값을 고름
				}
				else { // 상대가 선택하는 턴일 경우
					DP[k][k + step] = MIN(DP[k + 1][k + step], DP[k][k + step - 1]);
					// 상대가 선택하는 턴이므로 상대가 이익을 최소로 보는 값을 고름
				}
			}
		}
		printf("%d\n", DP[0][N - 1]);
	}
}