// 13232 Domain clusters
// https://www.acmicpc.net/problem/13232
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> answer, road, reverse_road;
stack<int> scc;
bool visited[10001], reverse_visited[10001];
int V, E, idx = 0;

void reverse_DFS(int v){ // 이 정점이 실제로 속한 사이클만큼 실행됨
	reverse_visited[v] = true;
	answer[idx].push_back(v);
	for (int i = 0; i < reverse_road[v].size(); i++){
		if (reverse_visited[reverse_road[v][i]] == false){
			reverse_DFS(reverse_road[v][i]);
		}
	}
	return;
}

void DFS(int v){ // 스택에 변수를 넣는 순서 결정(사이클 형성 순서)
	visited[v] = true;
	for (int i = 0; i < road[v].size(); i++){
		if (visited[road[v][i]] == false){
			DFS(road[v][i]);
		}
	}
	scc.push(v);
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2, MaxSize = 0;
	cin >> V;
	cin >> E;
	road.resize(V + 1);
	reverse_road.resize(V + 1);
	for (int e = 0; e < E; e++){
		cin >> v1 >> v2;
		road[v1].push_back(v2);
		reverse_road[v2].push_back(v1); // SCC는 유향 그래프 기준으로 돌아가기 때문에, 역순도 저장함
	}
	for (int v = 1; v <= V; v++){
		if (visited[v] == false){ // 아직 얼마나 큰 사이클에 존재하는지 모르므로
			DFS(v);
		}
	}
	while (!scc.empty()){ // 사이클 검증
		v1 = scc.top();	scc.pop();
		if (reverse_visited[v1] == false){
			answer.resize(idx + 1);
			reverse_DFS(v1);
			idx++;
		}
	}
	for (int i = 0; i < idx; i++){
		if (MaxSize < answer[i].size()){ // 지금까지 형성된 최대 크기 사이클보다도 더 큰 사이클이 있을 경우
			MaxSize = answer[i].size();
		}
	}
	cout << MaxSize;
}