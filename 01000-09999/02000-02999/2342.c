// 2342 Dance Dance Revolution
// https://www.acmicpc.net/problem/2342
// https://yjyoon-dev.github.io/boj/2021/02/15/boj-2342/ (YJYOON님의 블로그)에서 배웠습니다. 아직 DP가 많이 부족한가 봅니다.
#include <stdio.h>

int dp[100001][5][5] = {0, };
int command_list[100001];
int num, len = 0, answer;

int min(int a, int b){
	return a < b ? a : b;
}

int move(int start, int end){
	if (start == end){return 1;}
	switch(start){
		case 0:
			return 2;
		case 1:
			return end == 3 ? 4 : 3;
		case 2:
			return end == 4 ? 4 : 3;
		case 3:
			return end == 1 ? 4 : 3;
		case 4:
			return end == 2 ? 4 : 3;
		default: // 잘못된 입력
			return 999999;
	}
}

int DDR(int move_count, int left, int right){
	if (move_count == len){return 0;}
	if (dp[move_count][left][right] != 0){return dp[move_count][left][right];}
	return dp[move_count][left][right] = min(move(left, command_list[move_count]) + DDR(move_count + 1, command_list[move_count], right), move(right, command_list[move_count]) + DDR(move_count + 1, left, command_list[move_count]));
}

int main(){
	while (1){
		scanf("%d", &num);
		if (num == 0){break;}
		command_list[len++] = num;
	}
	answer = DDR(0, 0, 0);
	printf("%d", answer);
}