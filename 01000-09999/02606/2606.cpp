// 2606 바이러스
#include <iostream>
using namespace std;

int N, M;
int count = 0;
int graph[1001][1001] = {0, };
bool visit_DFS[1001] = {false, };


void DFS(int v){
	visit_DFS[v] = true;
	for (int i = 1; i <= N; i++){
		if (visit_DFS[i] == false && graph[v][i] == 1){
			count++;
			DFS(i);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	DFS(1);
	cout << count;
}