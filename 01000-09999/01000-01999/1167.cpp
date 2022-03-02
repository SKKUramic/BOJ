// 1167 트리의 지름
// https://www.acmicpc.net/problem/1167
// 1. 루트(1)에서 가장 먼 노드를 찾는다, 2. 그 노드로부터 가장 먼 노드까지의 거리가 지름이다.
#include <iostream>
#include <vector>
#include <utility>
//#include <cstring>
using namespace std;

int longest_path = -1;
int NODE;
vector<pair<int, int>> tree[100001]; // <next_node, weight>
bool node_visit[100001];

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
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, node, next_node, weight;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> node;
		while (1){
			cin >> next_node;
			if (next_node == -1){break;}
			cin >> weight;
			tree[node].push_back({next_node, weight});
		}
	}
	DFS(1, 0);
	DFS(NODE, 0);
	cout << longest_path;
}