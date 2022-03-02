// 17834 사자와 토끼
// https://www.acmicpc.net/problem/17834
// 이분 그래프 문제, 다행히도 모든 수풀은 연결되어 있다
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

bool valid = true;
bool visited[50001];
int bush, road;
ll answer = 0;
ll color[50001]; // 0: none, 1: red, 2: blue
ll color_count[3];
vector<ll> graph[50001];

void DFS(int x){
	if (valid == false || visited[x] == true){return;}
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++){
		if (visited[graph[x][i]] == true){
			if (color[graph[x][i]] != 0 && color[x] == color[graph[x][i]]){
				valid = false;
				return;
			}
		}
		else {
			color[graph[x][i]] = 3 - color[x];
			DFS(graph[x][i]);
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v;
	cin >> bush >> road;
	for (int i = 0; i < road; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	color[1] = 1;
	DFS(1);
	if (valid == false){
		cout << 0;
	}
	else {
		for (int i = 1; i <= bush; i++){
			color_count[color[i]]++;
		}
		cout << color_count[1] * color_count[2] * 2;
	}
}