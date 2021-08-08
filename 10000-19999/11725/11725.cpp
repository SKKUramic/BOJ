// 11725 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
bool visited[100001]; // idx 노드의 부모를 저장
vector<int> tree[100001]; // idx 노드와 연결된 다른 노드들을 저장함 (단, 누가 부모인지는 모름)

void find_parent(int node){
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++){
		if (visited[tree[node][i]] != true){ // 다음에 갈 노드가 아직 방문한 노드가 아니라면
			parent[tree[node][i]] = node; // 다음에 갈 노드의 부모는 현재 노드
			find_parent(tree[node][i]);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node_count, node1, node2;
	cin >> node_count;
	for (int i = 0; i < node_count - 1; i++){
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	find_parent(1);
	for (int i = 2; i <= node_count; i++){
		cout << parent[i] << '\n';
	}
}