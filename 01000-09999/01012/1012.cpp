// 1012 유기농 배추
#include <iostream>
using namespace std;

int N, M, K;
int one_count = 0;
int answer = 0;
int graph[50][50] = {0, };
//bool visit_DFS[2501] = {false, };


void DFS(int x, int y){
	graph[x][y] = 0;
	if (x > 0 && graph[x - 1][y] == 1){
		DFS(x - 1, y);
	}
	if (x < M - 1 && graph[x + 1][y] == 1){
		DFS(x + 1, y);
	}
	if (y > 0 && graph[x][y - 1] == 1){
		DFS(x, y - 1);
	}
	if (y < N - 1 && graph[x][y + 1] == 1){
		DFS(x, y + 1);
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2, test;
	cin >> test;
	for (int i = 0; i < test; i++){
		answer = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++){
			cin >> v1 >> v2;
			graph[v1][v2] = 1;
		}
		for (int a = 0; a < M; a++){
			for (int b = 0; b < N; b++){
				if (graph[a][b] == 1){
					DFS(a, b);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
}