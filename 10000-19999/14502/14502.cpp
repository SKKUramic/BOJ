// 14502 연구소
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, M, answer = 0;
int LAB[8][8];
vector<pair<int, int>> empty_room;
vector<pair<int, int>> virus;

void BFS(){
	int n, m, safe_room = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++){
		q.push(virus[i]);
	}
	while (!q.empty()){
		n = q.front().first;
		m = q.front().second;
		q.pop();
		if (n > 0 && LAB[n - 1][m] == 0){
			LAB[n - 1][m] = 2;
			q.push({n - 1, m});
		}
		if (n < N - 1 && LAB[n + 1][m] == 0){
			LAB[n + 1][m] = 2;
			q.push({n + 1, m});
		}
		if (m > 0 && LAB[n][m - 1] == 0){
			LAB[n][m - 1] = 2;
			q.push({n, m - 1});
		}
		if (m < M - 1 && LAB[n][m + 1] == 0){
			LAB[n][m + 1] = 2;
			q.push({n, m + 1});
		}
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			if (LAB[n][m] == 0){
				safe_room++;
			}
		}
	}
	if (safe_room > answer){answer = safe_room;}
	for (int v = 0; v < empty_room.size(); v++){
		LAB[empty_room[v].first][empty_room[v].second] = 0; // 복구
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v_size;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> LAB[n][m];
			if (LAB[n][m] == 0){
				empty_room.push_back({n, m});
			}
			else if (LAB[n][m] == 2){
				virus.push_back({n, m});
			}
		}
	}
	v_size = empty_room.size();
	for (int a = 0; a < v_size; a++){
		for (int b = a + 1; b < v_size; b++){
			for (int c = b + 1; c < v_size; c++){
				LAB[empty_room[a].first][empty_room[a].second] = 1;
				LAB[empty_room[b].first][empty_room[b].second] = 1;
				LAB[empty_room[c].first][empty_room[c].second] = 1;
				BFS();
				LAB[empty_room[a].first][empty_room[a].second] = 0;
				LAB[empty_room[b].first][empty_room[b].second] = 0;
				LAB[empty_room[c].first][empty_room[c].second] = 0;
			}
		}
	}
	cout << answer;
}