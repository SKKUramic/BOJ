// 17070 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070
// dp문제(BFS 씀ㅋㅋ)
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, pair<int, int>>> q; // <direction, <y, x>>, 0- 1\ 2|
int pipeline[20][20] = {0, };
int dp[20][20] = {0, };

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, size, y, x, count = 0;
	pair<int, pair<int, int>> pipe;
	cin >> N;
	q.push({0, {1, 2}});
	dp[1][2] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> pipeline[i][j];
		}
	}
	while (!q.empty()){
		size = q.size();
		while (size-- > 0){
			pipe = q.front();
			y = pipe.second.first;
			x = pipe.second.second;
			q.pop();
			if (x == N && y == N){count++; continue;}
			if (pipe.first == 0){
				if (x < N && pipeline[y][x + 1] == 0){
					q.push({0, {y, x + 1}});
					if (y < N && pipeline[y + 1][x] == 0 && pipeline[y + 1][x + 1] == 0){
						q.push({1, {y + 1, x + 1}});
					}
				}
			}
			else if (pipe.first == 1){
				if (x < N && pipeline[y][x + 1] == 0){
					q.push({0, {y, x + 1}});
				}
				if (y < N && pipeline[y + 1][x] == 0){
					q.push({2, {y + 1, x}});
				}
				if (x < N && y < N && pipeline[y + 1][x] == 0 && pipeline[y][x + 1] == 0 && pipeline[y + 1][x + 1] == 0){
					q.push({1, {y + 1, x + 1}});
				}
			}
			else if (pipe.first == 2){
				if (y < N && pipeline[y + 1][x] == 0){
					q.push({2, {y + 1, x}});
					if (x < N && pipeline[y][x + 1] == 0 && pipeline[y + 1][x + 1] == 0){
						q.push({1, {y + 1, x + 1}});
					}
				}
			}
		}
	}
	cout << count;
}