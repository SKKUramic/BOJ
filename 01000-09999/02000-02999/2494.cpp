// 2494 숫자 맞추기
// https://www.acmicpc.net/problem/2494
// 왼쪽이 증가, 오른쪽이 감소
// EVEernew님의 설명(https://everenew.tistory.com/197)을 배운 후 구현했습니다. 아직도 DP는 어렵네요
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct Screw{
	int total_turn = -1; // 지금까지 돌린 횟수
	int turn = 0; // 이번에 돌린 횟수
}Screw;

Screw DP[10001][10]; // [현재 나사 번호][현재 숫자]
string password, goal;
int password_num[10001], goal_num[10001];
int len;

int TurnScrew(int LeftTurn, int idx){ // 현재 나사 번호를 알려면 지금까지 왼쪽으로 돌린 횟수를 알아야 함
	if (idx == len){return 0;} // 그만 돌려~
	int current_num = (password_num[idx] + LeftTurn) % 10; // 현재 나사의 숫자
	if (DP[idx][current_num].total_turn != -1){return DP[idx][current_num].total_turn;} // 이미 구했다면 리턴
	
	int leftturn = (goal_num[idx] - current_num + 10) % 10;
	int rightturn = (current_num - goal_num[idx] + 10) % 10;
	int LEFT = TurnScrew(LeftTurn + leftturn, idx + 1) + leftturn;
	int RIGHT = TurnScrew(LeftTurn, idx + 1) + rightturn;
	
	if (LEFT < RIGHT){
		DP[idx][current_num].total_turn = LEFT;
		DP[idx][current_num].turn = leftturn;
	}
	else {
		DP[idx][current_num].total_turn = RIGHT;
		DP[idx][current_num].turn = -rightturn;
	}
	return DP[idx][current_num].total_turn;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> len;
	cin >> password;
	cin >> goal;
	for (int i = 0; i < len; i++){
		password_num[i] = password[i] - '0';
		goal_num[i] = goal[i] - '0';
	}
	cout << TurnScrew(0, 0) << '\n';
	int current_num;
	int leftturn = 0;
	for (int i = 0; i < len; i++){
		current_num = (password_num[i] + leftturn) % 10;
		cout << i + 1 << ' ' << DP[i][current_num].turn << '\n';
		if (DP[i][current_num].turn > 0){ // 왼쪽으로 돌렸을 경우 다음 번호에 변화가 생긴다
			leftturn += DP[i][current_num].turn;
		}
		
	}
}