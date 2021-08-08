// 1967 트리의 지름
// https://www.acmicpc.net/problem/1967
// 1167번 문제와 동일한 풀이방식으로 해결하였습니다.
// 1. 루트(1)에서 가장 먼 노드를 찾는다, 2. 그 노드로부터 가장 먼 노드까지의 거리가 지름이다.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int longest_path = -1;
int NODE;
vector<pair<int, int>> tree[10001]; // <next_node, weight>
bool node_visit[10001];

void DFS(int node, int weight_sum){
	if (weight_sum > longest_path){
		NODE = node;
		longest_path = weight_sum;
	}
	node_visit[node] = true;
	for (int n = 0; n < tree[node].size(); n++){
		if (node_visit[tree[node][n].first] == false){
			DFS(tree[node][n].first, weight_sum + tree[node][n].second);
		}
	}
	node_visit[node] = false;
	return;
}

int main(){
	int N, node, next_node, weight;
	cin >> N;
	for (int i = 0; i < N - 1; i++){
		cin >> node >> next_node >> weight;
		tree[node].push_back({next_node, weight});
		tree[next_node].push_back({node, weight});
	}
	DFS(1, 0);
	DFS(NODE, 0);
	cout << longest_path;
}