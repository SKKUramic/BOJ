// 1260 DFS와 BFS
#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int graph[1001][1001] = {0, };
bool visit_DFS[1001] = {false, };
bool visit_BFS[1001] = {false, };


void DFS(int v){
	cout << v << ' ';
	visit_DFS[v] = true;
	for (int i = 1; i <= N; i++){
		if (visit_DFS[i] == false && graph[v][i] == 1){
			DFS(i);
		}
	}
	return;
}

void BFS(int v){
	queue<int> q;
	visit_BFS[v] = true;
	q.push(v);
	while (!q.empty()){
		v = q.front();
		cout << v << ' ';
		q.pop();
		for (int i = 1; i <= N; i++){
			if (visit_BFS[i] == false && graph[v][i] == 1){
				visit_BFS[i] = true;
				q.push(i);
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++){
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	DFS(V);
	cout << '\n';
	BFS(V);
}