// 10292 Man in the Middle
// https://www.acmicpc.net/problem/10292
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[30001];
int visited[30001];
bool CUT[30001];
int V, E, T, Apoint, order;

int min(int a, int b){return a < b ? a : b;}

void initialize(int N){
	Apoint = 0; order = 1;
	for (int n = 0; n <= N; n++){
		visited[n] = 0;
		CUT[n] = false;
		graph[n].clear();
	}
	return;
}

int dfs(int v, bool isRoot){
	int ret, prev, next;
	int child = 0;
	visited[v] = order++;
	ret = visited[v];
	for (int i = 0; i < graph[v].size(); i++){
		next = graph[v][i];
		if (visited[next] != 0){
			ret = min(ret, visited[next]);
			continue;
		}
		child++;
		prev = dfs(next, false);
		if (isRoot == false && prev >= visited[v]){
			CUT[v] = true;
		}
		ret = min(ret, prev);
	}
	if (isRoot == true){
		CUT[v] = (child >= 2) ? true : false;
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2, dummy;
	cin >> T;
	while (T-- > 0){
		cin >> V >> E;
		for (int e = 0; e < E; e++){
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		for (int v = 1; v <= V; v++){
			if (visited[v] == 0){
				dummy = dfs(v, true);
			}
		}
		for (int v = 1; v <= V; v++){
			if (CUT[v] == true){Apoint++;}
		}
		if (Apoint > 0){cout << "YES\n";}
		else {cout << "NO\n";}
		initialize(V);
	}
}