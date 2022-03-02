// 2644 촌수계산
// https://www.acmicpc.net/problem/2644
#include <iostream>
#include <vector>
using namespace std;

int START, END, N, E, a, b, answer = -1;
bool visited[101];
vector<int> graph[101];

void DFS(int v, int count){
	if (visited[v] == true){return;}
	visited[v] = true;
	if (v == END){
		answer = count;
		return;
	}
	for (int i = 0; i < graph[v].size(); i++){
		DFS(graph[v][i], count + 1);
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> START >> END;
	cin >> E;
	for (int e = 0; e < E; e++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(START, 0);
	cout << answer;
}