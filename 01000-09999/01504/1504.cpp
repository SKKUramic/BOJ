// 1504 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INF 999999999
int City, Bus, Weight;
int u, v, w, A, B;
int way01, way02, way1, way21, way22, answer = -1;
vector<pair<int, int>> Dijkstra[1001]; // <목적지, 비용>
bool visited[1001];
int path[1001];

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

int FIND_Dijkstra(int start_node, int end_node){
	priority_queue<int, vector<pair<int, int>>, cmp> pq;
	pair<int, int> p;
	for (int i = 0; i <= 1000; i++){
		visited[i] = false;
		path[i] = INF;
	}
	path[start_node] = 0;
	for (int i = 0; i < Dijkstra[start_node].size(); i++){
		if (path[Dijkstra[start_node][i].first] > Dijkstra[start_node][i].second){ // 만약 출발 노드와 다음 노드가 같은 여러 간선이 있으면, 그 최솟값만 우선순위 큐에 넣는다.
			pq.push(Dijkstra[start_node][i]);
			path[Dijkstra[start_node][i].first] = Dijkstra[start_node][i].second; // 최단경로 갱신
		}
	}
	visited[start_node] = true;
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
	return path[end_node];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> City >> Bus;
	for (int b = 0; b < Bus; b++){
		cin >> u >> v >> w;
		Dijkstra[u].push_back({v, w});
		Dijkstra[v].push_back({u, w});
	}
	cin >> A >> B;
	way01 = FIND_Dijkstra(1, A);
	way02 = path[B]; // 1->B
	way1 = FIND_Dijkstra(A, B); // A->B랑 B->A랑 똑같음
	way21 = path[City]; // A->City
	way22 = FIND_Dijkstra(B, City);
	if (way01 != INF && way1 != INF && way22 != INF){ // 1->A->B->N이 존재할 때
		answer = way01 + way1 + way22;
	}
	if (way02 != INF && way1 != INF && way21 != INF){ // 1->B->A->N이 존재할 때
		if (answer > way02 + way1 + way21){
			answer = way02 + way1 + way21;
		}
	}
	cout << answer;
}