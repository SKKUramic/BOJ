// 15900 나무 탈출
// https://www.acmicpc.net/problem/15900
#include <iostream>
#include <vector>
using namespace std;

int NODE_COUNT;
long long int point = 0;
vector<int> tree[500001];
int tree_edge_count[500001] = {0, };
bool visited[500001] = {false, };

void DFS(int v, int count){
	visited[v] = true;
	int p = 0;
	for (int i = 0; i < tree_edge_count[v]; i++){
		if (visited[tree[v][i]] == false){
			DFS(tree[v][i], count + 1);
			p++;
		}
	}
	if (p == 0) {point += count;}
	visited[v] = false;
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node1, node2;
	cin >> NODE_COUNT;
	for (int i = 0; i < NODE_COUNT - 1; i++){
		cin >> node1 >> node2;
		tree_edge_count[node1]++; tree_edge_count[node2]++;
		tree[node1].push_back(node2); tree[node2].push_back(node1);
	}
	DFS(1, 0);
	if (point % 2 == 1){
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}