// 2178 미로 탐색
// https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, answer = 9999999;
bool flags = false;
char graph[100][100];

void print(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << graph[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
/*
void DFS(int x, int y, int step){
	if (x == N - 1 && y == M - 1 && answer > step){
		answer = step;
		return;
	}
	if (graph[x][y] == '0' || graph[x][y] == 'X'){
		return;
	}
	graph[x][y] = 'X';
	//print();
	if (x > 0 && graph[x - 1][y] == '1'){
		DFS(x - 1, y, step + 1);
	}
	if (x < N - 1 && graph[x + 1][y] == '1'){
		DFS(x + 1, y, step + 1);
	}
	if (y > 0 && graph[x][y - 1] == '1'){
		DFS(x, y - 1, step + 1);
	}
	if (y < M - 1 && graph[x][y + 1] == '1'){
		DFS(x, y + 1, step + 1);
	}
	graph[x][y] = '1';
	return;
}*/
void BFS(){
	queue<pair<int, int>> q;
	int x = 0, y = 0, step = 1, pop_count = 1, temp;
	graph[0][0] = 'X';
	q.push({x, y});
	while (!q.empty() && !flags){
		temp = 0;
		for (int i = 0; i < pop_count; i++){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == N - 1 && y == M - 1){
				answer = step;
				flags = true;
				break;
			}
			if (x > 0 && graph[x - 1][y] == '1'){
				graph[x - 1][y] = 'X';
				q.push({x - 1, y});
				temp++;
			}
			if (x < N - 1 && graph[x + 1][y] == '1'){
				graph[x + 1][y] = 'X';
				q.push({x + 1, y});
				temp++;
			}
			if (y > 0 && graph[x][y - 1] == '1'){
				graph[x][y - 1] = 'X';
				q.push({x, y - 1});
				temp++;
			}
			if (y < M - 1 && graph[x][y + 1] == '1'){
				graph[x][y + 1] = 'X';
				q.push({x, y + 1});
				temp++;
			}
		}
		pop_count = temp;
		step++;
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> graph[i];
	}
	BFS();
	//DFS(0, 0, 1);
	cout << answer;
}