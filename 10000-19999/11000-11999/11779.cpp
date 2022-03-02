// 11779 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779
// 1916 최소비용 구하기 문제에서 경로를 추가하였습니다
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INF 999999999
int City, Bus;
int u, v, w, A, B;
vector<pair<int, int>> Dijkstra[1001]; // <목적지, 비용>
bool visited[1001];
int path[1001];
int route[1001]; // route[idx]: 어떤 도시에서 idx번 도시로 이동한 것인지 저장되어있음

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
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
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
			route[Dijkstra[start_node][i].first] = start_node; // 우선 시작노드가 가는 노드가 어딘지 저장
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
				route[Dijkstra[p.first][i].first] = p.first; // 1->3이라면 route[3] = 1로 저장된다
			}
		}
	}
	return path[end_node];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> route_list;
	cin >> City >> Bus;
	for (int b = 0; b < Bus; b++){
		cin >> u >> v >> w;
		Dijkstra[u].push_back({v, w});
	}
	cin >> A >> B;
	int answer = FIND_Dijkstra(A, B);
	while (B != 0){
		route_list.push_back(B);
		B = route[B];
	}
	cout << answer << '\n';
	cout << route_list.size() << '\n';
	for (int i = route_list.size() - 1; i >= 0; i--){
		cout << route_list[i] << ' ';
	}
}