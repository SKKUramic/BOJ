// 1865 웜홀
// https://www.acmicpc.net/problem/1865
// Bellman-Ford 알고리즘을 배우기 위한 문제, https://4z7l.github.io/2021/03/04/algorithms-boj-1865.html(HERSTORY님의 블로그)에서 많은 도움 받았습니다.
#include <iostream>
#include <vector>
#define INF 99999999
using namespace std;

typedef struct edge {
	int s, e, t;
} edge;

vector<edge> EDGE;

int TC, N, M, W;

bool Bellman_Ford(){
	vector<int> dist(N + 1, INF);
	dist[1] = 0; // init;
	int s, e, t;
	for (int n = 1; n < N; n++){ // 도시의 수 - 1만큼 검사, 시작점->시작점은 안해도 되서?
		for (int k = 0; k < EDGE.size(); k++){
			s = EDGE[k].s;
			e = EDGE[k].e;
			t = EDGE[k].t;
			if (dist[e] > dist[s] + t){ // (1에서 e점으로 가는 시간)보다 (1에서 s점으로 가는 시간 + s점에서 e로 가는 시간)이 더 짧을 경우 갱신
				dist[e] = dist[s] + t; // 웜홀이 존재하지 않으면 절대로 갱신되지 않는다. 초기값이 dist[s] = dist[e] = INF이기 때문
			}
		}
	}
	for (int k = 0; k < EDGE.size(); k++){
		s = EDGE[k].s;
		e = EDGE[k].e;
		t = EDGE[k].t;
		if (dist[e] > dist[s] + t){ // 최종 버전에서 (1에서 e점으로 가는 총 시간)보다 (1에서 s점으로 가는 총 시간 + s점에서 e로 가는 시간)이 더 짧을 경우 true 리턴
			return true; // 위의 조건을 만족하면 s에서 e로 가는 시간보다 e에서 s로 웜홀을 타고 가는 시간이 더 이득이라는 소리
		}
	}
	return false;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int S, E, T;
	cin >> TC;
	while (TC-- > 0){
		EDGE.clear();
		cin >> N >> M >> W;
		for (int m = 0; m < M; m++){
			cin >> S >> E >> T;
			EDGE.push_back({S, E, T});
			EDGE.push_back({E, S, T});
		}
		for (int w = 0; w < W; w++){
			cin >> S >> E >> T;
			EDGE.push_back({S, E, -T});
		}
		if (Bellman_Ford() == true){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}