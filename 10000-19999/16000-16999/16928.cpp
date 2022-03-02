// 16928 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> board[101];
queue<int> q;
bool inside_queue[101];
int radder_list[101];
int snake_list[101];

int BFS(){
	int cur_idx;
	int count = 1;
	vector<int> arr;
	q.push(1); // 시작점
	inside_queue[1] = true;
	while(!q.empty() && count < 100){ // 큐가 비거나 100번 움직였을 경우 종료, 둘 다 사실상 쓰일 일이 없음
		while (!q.empty()){
			arr.push_back(q.front()); // 현재 칸의 주소를 벡터에 저장
			inside_queue[q.front()] = false; // 이 칸에서 벗어난 판정이 됨
			q.pop();
		}
		while (!arr.empty()){ // 현재 칸으로부터 갈 수 있는 모든 칸을 구함
			cur_idx = arr.back();
			arr.pop_back();
			for (int i = 0; i < board[cur_idx].size(); i++){ // 현재 칸에서 갈 수 있는 곳을 조사
				if (board[cur_idx][i] == 100){ // 도착점에 도달했을 경우
					return count;
				}
				if (inside_queue[board[cur_idx][i]] == false){ // 갈 수 있는 칸이며, 큐 안에 그 수가 없을 때만 넣음
					q.push(board[cur_idx][i]);
					inside_queue[board[cur_idx][i]] = true;
				}
			}
		}
		count++;
	}
	return count; // 이게 작동됐다면 뭔가 문제가 있음
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer;
	int radder, snake, go, arrive;
	cin >> radder >> snake;
	while (radder-- > 0){
		cin >> go >> arrive;
		radder_list[go] = arrive;
	}
	while (snake-- > 0){
		cin >> go >> arrive;
		snake_list[go] = arrive;
	}
	for (int x = 1; x <= 100; x++){
		for (int y = x + 1; y <= x + 6; y++){
			if (y > 100){
				break;
			}
			if (radder_list[y] != 0){
				board[x].push_back(radder_list[y]);
			}
			else if (snake_list[y] != 0){
				board[x].push_back(snake_list[y]);
			}
			else {
				board[x].push_back(y);
			}
		}
	}
	answer = BFS();
	cout << answer;
}