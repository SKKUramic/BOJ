// 11724 연결 요소의 개수
// https://www.acmicpc.net/problem/11724
// BFS이든 DFS이든 상관 없습니다.
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int graph[1001][1001] = {0, };
bool visited[1001] = {false, };
int visit_count = 0;

void BFS(int x){
	visited[x] = true;
	visit_count++;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++){
			if (!visited[i] && graph[x][i] == 1){
				visited[i] = true;
				q.push(i);
				visit_count++;
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v, Component_count = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	for (int i = 1; visit_count != N; i++){
		if (!visited[i]){
			BFS(i);
			Component_count++;
		}
	}
	cout << Component_count;
}