// 11266 단절점
// https://www.acmicpc.net/problem/11266
// https://www.crocus.co.kr/1164(Crocus님의 블로그)에서 배웠습니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
int visited[10001]; // v번 정점에 몇번째로 방문했는지
bool CUT[100001];
int V, E, Apoint = 0, order = 1;

int min(int a, int b){return a < b ? a : b;}

int dfs(int v, bool isRoot){ // 현재 정점에서 갈 수 있는 정점들 중, 방문 순서가 가장 빠른 정점을 리턴
	int ret, prev, next;
	int child = 0;
	visited[v] = order++; // dfs를 하면서, 방문한 순서
	ret = visited[v];
	for (int i = 0; i < graph[v].size(); i++){
		next = graph[v][i];
		if (visited[next] != 0){ // 이미 방문한 곳일 때
			ret = min(ret, visited[next]); // 현재 정점과 다음 정점 중 어딜 먼저 방문했는지 저장
			continue;
		}
		child++;
		prev = dfs(next, false); // 다음 정점의 방문 순서 저장
		if (isRoot == false && prev >= visited[v]){
			// 현재 정점이 루트가 아니고, 현재 정점보다 다음 정점을 늦게 방문했을 경우
			// 즉, 현재 정점보다 방문 순서가 빠른 정점에 방문할 수 없다면 이 점은 단절점이다.
			CUT[v] = true;
		}
		ret = min(ret, prev);
	}
	if (isRoot == true){ // 현재 정점이 루트일 때, 자식이 둘 이상이면 무조건 단절점이다
		CUT[v] = (child >= 2) ? true : false;
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2, dummy;
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
	cout << Apoint << '\n';
	for (int  v = 1; v <= V; v++){
		if (CUT[v] == true){cout << v << ' ';}
	}
}