// 1753 최단경로
// https://www.acmicpc.net/problem/1753
// 다익스트라 알고리즘 배우기 https://www.acmicpc.net/board/view/34516
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 9999999

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
		if (a.second == b.second){
			return a.first > b.first;
		}
		else {
			return a.second > b.second;
		}
    }
};

vector<pair<int, int>> Dijkstra[20001]; // v, w
priority_queue<int, vector<pair<int, int>>, cmp> pq; // v, w_sum
bool visited[20001];
int path[20001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, start_node;
	int u, v, w, pq_size, true_count = 0;
	pair<int, int> p;
	cin >> V >> E;
	cin >> start_node;
	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;
		Dijkstra[u].push_back({v, w}); // 일단 다 벡터에 저장함
	}
	for (int i = 0; i <= V; i++){path[i] = INF;} // 일단 전부 INF로 초기화
	path[start_node] = 0; // 자기 자신은 0
	for (int i = 0; i < Dijkstra[start_node].size(); i++){
		if (path[Dijkstra[start_node][i].first] > Dijkstra[start_node][i].second){ // 만약 출발 노드와 다음 노드가 같은 여러 간선이 있으면, 그 최솟값만 우선순위 큐에 넣는다.
			pq.push(Dijkstra[start_node][i]);
			path[Dijkstra[start_node][i].first] = Dijkstra[start_node][i].second; // 최단경로 갱신
		}
	}
	visited[start_node] = true; // 출발 노드는 이미 방문함
	while(!pq.empty()){
		p = pq.top(); // 가장 가까운 노드로 이동
		pq.pop();
		if (visited[p.first] == true){continue;} // 이미 방문했다면 그냥 넘김
		visited[p.first] = true; // 이동한 노드에 방문한 것으로 저장
		for (int i = 0; i < Dijkstra[p.first].size(); i++){
			if (path[Dijkstra[p.first][i].first] > p.second + Dijkstra[p.first][i].second){ // 다음 노드로 갈 때의 경로 합이 현재 저장된 최단경로보다 짧을 때만 갱신한다.
				pq.push({Dijkstra[p.first][i].first, p.second + Dijkstra[p.first][i].second});
				path[Dijkstra[p.first][i].first] = p.second + Dijkstra[p.first][i].second;
			}
		}
	}
	
	for (int i = 1; i <= V; i++){
		if (path[i] == INF){ // 시작 노드에서 i로 가는 길이 없을 경우
			cout << "INF\n";
		}
		else {
			cout << path[i] << '\n';
		}
	}
}