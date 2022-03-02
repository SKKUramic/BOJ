// 1707 이분 그래프
// https://www.acmicpc.net/problem/1707
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 20000
using namespace std;

bool visited[MAX + 1];
int point_color[MAX + 1]; // 0: 방문 안 함, 1: RED, -1: BLUE
vector<int> edge_list[MAX + 1];

void BFS(int N, int start){
	int v, q_size, next, color = 1;
	queue<int> q;
	visited[start] = true;
	point_color[start] = color;
	color = -color;
	q.push(start);
	while (!q.empty()){
		q_size = q.size();
		while (q_size-- > 0){
			v = q.front();
			q.pop();
			for (int i = 0; i < edge_list[v].size(); i++){
				next = edge_list[v][i];
				if (visited[next] == false){
					visited[next] = true;
					point_color[next] = color;
					q.push(next);
				}
			}
		}
		color = -color;
	}
	return;
}

int main(){
	bool flag;
	int TC, V, E, edge;
	cin >> TC;
	while (TC-- > 0){
		int L, R;
		flag = true;
		memset(visited, false, sizeof(bool) * (MAX + 1));
		memset(point_color, 0, sizeof(int) * (MAX + 1));
		cin >> V >> E;
		for (int e = 0; e < E; e++){
			cin >> L >> R;
			edge_list[L].push_back(R);
			edge_list[R].push_back(L);
		}
		for (int v = 1; v <= V; v++){
			if (visited[v] == false){
				BFS(V, v);
			}
		}
		for (int v = 1; v <= V; v++){
			for (int e = 0; e < edge_list[v].size(); e++){
				edge = edge_list[v][e];
				if (point_color[v] == point_color[edge]){
					flag = false;
					break;
				}
			}
			if (flag == false) {break;}
		}
		if (flag == true) {cout << "YES\n";}
		else {cout << "NO\n";}
		for (int i = 0; i <= V; i++) {edge_list[i].clear();}
	}
}