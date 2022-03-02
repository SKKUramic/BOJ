// 14501 퇴사
// https://www.acmicpc.net/problem/14501
#include <stdio.h>

int N;
int arr[20][2] = {0, };
int DP[20] = {0, }; // N일이 끝날 때 얻을 수 있는 최대 이익

int maxret(int a, int b){return a > b ? a : b;}

int main(){
	int end_day, max = -1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int day = 1; day <= N + 1; day++){
		for (int past = 1; past < day; past++){
			DP[day] = maxret(DP[day], DP[past]);
			if (past + arr[past][0] == day){
				DP[day] = maxret(DP[day], DP[past] + arr[past][1]);
			}
		}
	}
	for (int i = 1; i <= N + 1; i++){
		if (max < DP[i]){max = DP[i];}
	}
	printf("%d", max);
}