// 2206 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
#include <iostream>
#include <queue>
using namespace std;

int N, M, answer;
char room_map[1001][1001];
int room_with_wall[2][1001][1001]; // [do_break][n][m], 돌을 부수지 않은 차원의 미로와 돌을 부순 차원의 미로를 별개로 보며 간다

int BFS(){
	int q_size, do_break, n, m;
	queue<pair<int, pair<int, int>>> q; // <do_break, <n, m>>
	q.push({0, {1, 1}});
	room_with_wall[0][1][1] = 1;
	while (!q.empty()){
		q_size = q.size();
		while (q_size-- > 0){
			do_break = q.front().first;
			n = q.front().second.first;
			m = q.front().second.second;
			q.pop();
			if (n == N && m == M){
				return room_with_wall[do_break][N][M];
			}
			// 여러분들은 이렇게 코드 더럽게 짜지 마십쇼ㅠㅠ
			if (n > 1){
				if (room_map[n - 1][m] == '1' && do_break == 0){
					room_with_wall[do_break + 1][n - 1][m] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break + 1, {n - 1, m}});
				}
				if (room_map[n - 1][m] == '0' && room_with_wall[do_break][n - 1][m] == 0){
					room_with_wall[do_break][n - 1][m] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break, {n - 1, m}});
				}
			}
			if (n < N){
				if (room_map[n + 1][m] == '1' && do_break == 0){
					room_with_wall[do_break + 1][n + 1][m] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break + 1, {n + 1, m}});
				}
				if (room_map[n + 1][m] == '0' && room_with_wall[do_break][n + 1][m] == 0){
					room_with_wall[do_break][n + 1][m] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break, {n + 1, m}});
				}
			}
			if (m > 1){
				if (room_map[n][m - 1] == '1' && do_break == 0){
					room_with_wall[do_break + 1][n][m - 1] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break + 1, {n, m - 1}});
				}
				if (room_map[n][m - 1] == '0' && room_with_wall[do_break][n][m - 1] == 0){
					room_with_wall[do_break][n][m - 1] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break, {n, m - 1}});
				}
			}
			if (m < M){
				if (room_map[n][m + 1] == '1' && do_break == 0){
					room_with_wall[do_break + 1][n][m + 1] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break + 1, {n, m + 1}});
				}
				if (room_map[n][m + 1] == '0' && room_with_wall[do_break][n][m + 1] == 0){
					room_with_wall[do_break][n][m + 1] = room_with_wall[do_break][n][m] + 1;
					q.push({do_break, {n, m + 1}});
				}
			}
		}
	}
	return -1;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			cin >> room_map[n][m];
		}
	}
	cout << BFS();
}