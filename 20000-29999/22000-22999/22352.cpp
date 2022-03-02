// 23252 항체 인식
// UCPC 2021 예선 B번이었습니다
// https://www.acmicpc.net/problem/22352
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int before[101][101];
int after[101][101];
bool visited[101][101];

void BFS(int y, int x, int value){
	queue<pair<int, int>> q;
	int px, py;
	visited[y][x] = true;
	int before_value = before[y][x];
	before[y][x] = value;
	q.push({y, x});
	while (!q.empty()){
		int q_size = q.size();
		for (int i = 1; i <= q_size; i++){
			py = q.front().first; px = q.front().second;
			q.pop();
			if (py > 0 && visited[py - 1][px] == false && before[py - 1][px] == before_value){
				visited[py - 1][px] = true;
				q.push({py - 1, px});
				before[py - 1][px] = value;
			}
			if (py < N - 1 && visited[py + 1][px] == false && before[py + 1][px] == before_value){
				visited[py + 1][px] = true;
				q.push({py + 1, px});
				before[py + 1][px] = value;
			}
			if (px > 0 && visited[py][px - 1] == false && before[py][px - 1] == before_value){
				visited[py][px - 1] = true;
				q.push({py, px - 1});
				before[py][px - 1] = value;
			}
			if (px < M - 1 && visited[py][px + 1] == false && before[py][px + 1] == before_value){
				visited[py][px + 1] = true;
				q.push({py, px + 1});
				before[py][px + 1] = value;
			}
		}
	}
	return;
}

int main(){
	int x = -1, y = -1, value;
	bool answer_flag = true;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> before[n][m];
		}
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> after[n][m];
		}
	}
	for (int n = 0; n < N; n++){
		if (x != -1 && y != -1){break;}
		for (int m = 0; m < M; m++){
			if (before[n][m] != after[n][m]){
				y = n; x = m; value = after[n][m];
				break;
			}
		}
	}
	BFS(y, x, value);
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			if (before[n][m] != after[n][m]){
				answer_flag = false;
			}
		}
	}
	if (!answer_flag){cout << "NO";}
	else {cout << "YES";}
	return 0;
}