// 1028 다이아몬드 광산
// https://www.acmicpc.net/problem/1028
#include <iostream>
#include <string>
using namespace std;

int R, C, max_diamond = 1;
bool exist_diamond = false;
int mine[750][750], left_bottom_dp[750][750], right_bottom_dp[750][750];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int len, size;
	string s;
	cin >> R >> C;
	for (int r = 0; r < R; r++){
		cin >> s;
		for (int c = 0; c < C; c++){
			mine[r][c] = s[c] - '0';
			if (mine[r][c] == 1){exist_diamond = true;}
		}
	}
	if (exist_diamond == false){ // 1이 없을 때
		cout << '0';
		return 0;
	}
	for (int r = 0; r < R; r++){ // 어떤 변의 꼭짓점(r, c)이 좌하단점일 때, 그 변의 최대 길이를 저장함
		for (int c = 0; c < C; c++){
			if (r == 0){
				left_bottom_dp[r][c] = mine[r][c]; // 맨 윗줄일 경우 그 자리에 다이아몬드가 있는지 없는지를 저장
			}
			else {
				if (c == C - 1){left_bottom_dp[r][c] = mine[r][c];}
				else {
					if (mine[r][c] == 0){ // 1이 연속되지 않을 경우
						left_bottom_dp[r][c] = 0;
					}
					else { // 1이 연속되어 있을 경우
						left_bottom_dp[r][c] = left_bottom_dp[r - 1][c + 1] + 1;
					}
				}
			}
		}
	}
	for (int r = 0; r < R; r++){ // 어떤 변의 꼭짓점(r, c)이 우하단점일 때, 그 변의 최대 길이를 저장함
		for (int c = 0; c < C; c++){
			if (r == 0){
				right_bottom_dp[r][c] = mine[r][c];
			}
			else {
				if (c == 0) {right_bottom_dp[r][c] = mine[r][c];}
				else {
					if (mine[r][c] == 0){
						right_bottom_dp[r][c] = 0;
					}
					else {
						right_bottom_dp[r][c] = right_bottom_dp[r - 1][c - 1] + 1;
					}
				}
			}
		}
	}
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			len = 0; size = 0;
			while (r - len >= 0 && r + len < R && c - len >= 0 && c + len < C){ // 다이아몬드가 형성될 수 있는 조건
				if (left_bottom_dp[r][c - len] >= len + 1 && left_bottom_dp[r + len][c] >= len + 1 && right_bottom_dp[r][c + len] >= len + 1 && right_bottom_dp[r + len][c] >= len + 1){
					// 네 개의 변 모두 존재한다면(끊겨있는 것 없이) 그 사이즈를 저장한다
					size = len + 1;
				}
				len++;
			}
			if (size > max_diamond){max_diamond = size;}
		}
		
	}
	cout << max_diamond;
}