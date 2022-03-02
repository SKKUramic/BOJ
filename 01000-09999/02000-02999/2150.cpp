// 2150 Strongly Connected Component
// https://www.acmicpc.net/problem/2150
// 코사라주 알고리즘을 통해 SCC의 개수를 알아내는 문제
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> answer, road, reverse_road;
stack<int> scc;
bool visited[10001], reverse_visited[10001];
int V, E, idx = 0;

void reverse_DFS(int v){
	reverse_visited[v] = true;
	answer[idx].push_back(v);
	for (int i = 0; i < reverse_road[v].size(); i++){
		if (reverse_visited[reverse_road[v][i]] == false){
			reverse_DFS(reverse_road[v][i]);
		}
	}
	return;
}

void DFS(int v){
	visited[v] = true;
	for (int i = 0; i < road[v].size(); i++){
		if (visited[road[v][i]] == false){
			DFS(road[v][i]);
		}
	}
	scc.push(v);
	return;
}

bool cmp(vector<int> a, vector<int> b){
	return a[0] < b[0];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2;
	cin >> V >> E;
	road.resize(V + 1);
	reverse_road.resize(V + 1);
	for (int e = 0; e < E; e++){
		cin >> v1 >> v2;
		road[v1].push_back(v2);
		reverse_road[v2].push_back(v1);
	}
	for (int v = 1; v <= V; v++){
		if (visited[v] == false){
			DFS(v);
		}
	}
	while (!scc.empty()){
		v1 = scc.top();	scc.pop();
		if (reverse_visited[v1] == false){
			answer.resize(idx + 1);
			reverse_DFS(v1);
			sort(answer[idx].begin(), answer[idx].end());
			answer[idx].push_back(-1);
			idx++;
		}
	}
	sort(answer.begin(), answer.end());
	cout << idx << '\n';
	for (int i = 0; i < idx; i++){
		for (int j = 0; j < answer[i].size(); j++){
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}