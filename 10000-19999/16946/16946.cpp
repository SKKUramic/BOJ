// 16946 벽 부수고 이동하기 4
// https://www.acmicpc.net/problem/16946
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> wall; // <y, x>
int room[1001][1001]; // 그래프 저장
int parent[1001][1001]; // 구역의 부모를 저장함, 벽의 상하좌우를 조사할 때 같은 구역을 중복으로 세는 것을 방지함
bool visit[1001][1001] = {false, }; // 중복 검사 방지
int N, M, wall_len, sum;

void BFS(int y, int x){ // 0으로 차 있는 공간에 빈 공간이 얼마나 있는지 저장함
	queue<pair<int, int>> q, save; // save는 빈 공간의 주소를 저장함
	pair<int, int> p;
	int count = 0;
	q.push({y, x});
	visit[y][x] = true;
	count++;
	while (!q.empty()){
		p = q.front();
		save.push(p);
		q.pop();
		if (p.first > 1 && room[p.first - 1][p.second] == 0 && visit[p.first - 1][p.second] == false){
			q.push({p.first - 1, p.second});
			visit[p.first - 1][p.second] = true;
			count++;
		}
		if (p.first < N && room[p.first + 1][p.second] == 0 && visit[p.first + 1][p.second] == false){
			q.push({p.first + 1, p.second});
			visit[p.first + 1][p.second] = true;
			count++;
		}
		if (p.second > 1 && room[p.first][p.second - 1] == 0 && visit[p.first][p.second - 1] == false){
			q.push({p.first, p.second - 1});
			visit[p.first][p.second - 1] = true;
			count++;
		}
		if (p.second < M && room[p.first][p.second + 1] == 0 && visit[p.first][p.second + 1] == false){
			q.push({p.first, p.second + 1});
			visit[p.first][p.second + 1] = true;
			count++;
		}	
	}
	while (!save.empty()){
		p = save.front();
		visit[p.first][p.second] = false;
		room[p.first][p.second] = -count;
		parent[p.first][p.second] = 1001 * y + x; // 주소를 hashing 기법을 이용해 저장
		save.pop();
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> N >> M;
	for (int n = 1; n <= N; n++){
		cin >> s;
		for (int m = 1; m <= M; m++){
			room[n][m] = s[m - 1] - '0';
			if (room[n][m] == 1){
				wall.push_back({n, m});
			}
		}
	}
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			if (room[n][m] == 0){
				BFS(n, m);
			}
		}
	}
	wall_len = wall.size();
	pair<int, int> p;
	int y, x;
	for (int w = 0; w < wall_len; w++){ // 이 벽을 파괴하면 거기서 갈 수 있는 빈 공간이 얼마나 있는지 검사함
		vector<int> parent_list;
		sum = 0;
		p = wall[w];
		if (p.first > 1 && room[p.first - 1][p.second] < 0){
			parent_list.push_back(parent[p.first - 1][p.second]);
		}
		if (p.first < N && room[p.first + 1][p.second] < 0){
			parent_list.push_back(parent[p.first + 1][p.second]);
		}
		if (p.second > 1 && room[p.first][p.second - 1] < 0){
			parent_list.push_back(parent[p.first][p.second - 1]);
		}
		if (p.second < M && room[p.first][p.second + 1] < 0){
			parent_list.push_back(parent[p.first][p.second + 1]);
		}
		sort(parent_list.begin(), parent_list.end());
		if (parent_list.size() == 0){
			room[wall[w].first][wall[w].second] = 1;
		}
		else if (parent_list.size() == 1){
			y = parent_list[0] / 1001;
			x = parent_list[0] % 1001;
			room[wall[w].first][wall[w].second] = -(room[y][x] - 1);
		}
		else {
			for (int i = 0; i < parent_list.size() - 1; i++){
				if (parent_list[i] == parent_list[i + 1]){
					parent_list[i] = -1;
				}
			}
			for (int i = 0; i < parent_list.size(); i++){
				if (parent_list[i] != -1){
					y = parent_list[i] / 1001;
					x = parent_list[i] % 1001;
					sum += room[y][x];
				}
			}
			sum--;
			room[wall[w].first][wall[w].second] = -sum;
		}
	}
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			if (room[n][m] < 0){
				cout << '0';
			}
			else {
				cout << room[n][m] % 10;
			}
		}
		cout << '\n';
	}
}