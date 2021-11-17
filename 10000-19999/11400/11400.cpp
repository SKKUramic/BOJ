// 11400 단절선
// https://www.acmicpc.net/problem/11400
// https://www.crocus.co.kr/1164(Crocus님의 블로그)에서 배웠습니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001]; // v번 정점에 몇번째로 방문했는지
vector<pair<int, int>> CUT;
int V, E, order = 1;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int dfs(int v, int parent){
	int ret, prev, next;
	visited[v] = order++; // dfs를 하면서, 방문한 순서
	ret = visited[v];
	for (int i = 0; i < graph[v].size(); i++){
		next = graph[v][i];
		if (next == parent){ // 자기 자신을 가리킴
			continue;
		}
		if (visited[next] != 0){
			ret = min(ret, visited[next]);
			continue;
		}
		prev = dfs(next, v); // 다음 정점의 부모는 현재 정점
		if (prev > visited[v]){
			CUT.push_back({min(v, next), max(v, next)});
		}
		ret = min(ret, prev);
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
			dummy = dfs(v, 0); // 0 = 루트로 지정
		}
	}
	sort(CUT.begin(), CUT.end());
	cout << CUT.size() << '\n';
	for (int v = 0; v < CUT.size(); v++){
		cout << CUT[v].first << ' ' << CUT[v].second << '\n';
	}
}