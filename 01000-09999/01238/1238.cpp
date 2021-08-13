// 1238 파티
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 999999999;
using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
		if (a.second == b.second){return a.first > b.first;}
		else {return a.second > b.second;}
    }
};

vector<pair<int, int>> Dijkstra[10001]; // <목적지, 시간>
vector<pair<int, int>> Dijkstra_reverse[10001];
priority_queue<int, vector<pair<int, int>>, cmp> pq; // <목적지, 시간>에서 시간이 가장 짧은 게 top으로, 시간이 같다면 목적지가 가장 작은 값이 top으로
int path[10001];
int path_reverse[10001];
bool visited[20001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, start_node;
	int start, end, weight;
	pair<int, int> p;
	cin >> N >> M >> start_node;
	for (int m = 0; m < M; m++){
		cin >> start >> end >> weight;
		Dijkstra[start].push_back({end, weight});
		Dijkstra_reverse[end].push_back({start, weight});
	}
	for (int i = 0; i <= 10000; i++){path[i] = INF; path_reverse[i] = INF} // 일단 전부 INF로 초기화
	path[start_node] = 0; // 시작점은 시간이 안 걸림
	for (int i = 0; i < Dijkstra[start_node].size(); i++){
		if (path[Dijkstra[start_node][i].first] > Dijkstra[start_node][i].second){ // 목적지로의 노드까지의 경로가 최솟값이면 갱신하기
			pq.push(Dijkstra[start_node][i]);
			path[Dijkstra[start_node][i].first] = Dijkstra[start_node][i].second; // 최단경로 갱신
		}
	}
	visited[start_node] = true;
	while (!pq.empty()){
		p = pq.top();
		pq.pop();
		if (visited[p.first] == true){continue;}
		visited[p.first] = true;
		for (int i = 0; i < Dijkstra[p.first].size(); i++){
			if (path[Dijkstra[p.first][i].first] > p.second + Dijkstra[p.first][i].second){ // 다음 노드로 갈 때의 경로 합이 현재 저장된 최단경로보다 짧을 때만 갱신한다.
				pq.push({Dijkstra[p.first][i].first, p.second + Dijkstra[p.first][i].second});
				path[Dijkstra[p.first][i].first] = p.second + Dijkstra[p.first][i].second;
			}
		}
	}
	// initializing
	while (!pq.empty()){pq.pop();}
	for (int i = 0; i <= 10000; i++){visited[i] = false;}
	
	path_reverse[start_node] = 0;
	for (int i = 0; i < Dijkstra_reverse[start_node].size(); i++){
		if (path_reverse[Dijkstra_reverse[start_node][i].first] > Dijkstra_reverse[start_node][i].second){ // 목적지로의 노드까지의 경로가 최솟값이면 갱신하기
			pq.push(Dijkstra_reverse[start_node][i]);
			path_reverse[Dijkstra_reverse[start_node][i].first] = Dijkstra_reverse[start_node][i].second; // 최단경로 갱신
		}
	}
	visited[start_node] = true;
	while (!pq.empty()){
		p = pq.top();
		pq.pop();
		if (visited[p.first] == true){continue;}
		visited[p.first] = true;
		for (int i = 0; i < Dijkstra_reverse[p.first].size(); i++){
			if (path_reverse[Dijkstra_reverse[p.first][i].first] > p.second + Dijkstra_reverse[p.first][i].second){ // 다음 노드로 갈 때의 경로 합이 현재 저장된 최단경로보다 짧을 때만 갱신한다.
				pq.push({Dijkstra_reverse[p.first][i].first, p.second + Dijkstra_reverse[p.first][i].second});
				path_reverse[Dijkstra_reverse[p.first][i].first] = p.second + Dijkstra_reverse[p.first][i].second;
			}
		}
	}
	int max_time = 0;
	for (int i = 1; i <= N; i++){
		if (path[i] + path_reverse[i] > max_time){
			max_time = path[i] + path_reverse[i];
		}
	}
	cout << max_time;
}