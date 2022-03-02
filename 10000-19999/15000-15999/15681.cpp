// 15681 트리와 쿼리
// https://www.acmicpc.net/problem/15681
#include <iostream>
#include <vector>
using namespace std;

vector<int> Tree[100001];
int DP[100001] = {0, };
bool visited[100001];

void DFS(int v){
	visited[v] = true;
	DP[v] = 1; // 자기 자신만 존재하는 서브트리
	for (int i = 0; i < Tree[v].size(); i++){
		int child = Tree[v][i];
		if (visited[child] == false){
			DFS(child);
			DP[v] += DP[child];
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, root, Q;
	int u, v, find;
	cin >> N >> root >> Q;
	for (int n = 0; n < N - 1; n++){
		cin >> u >> v;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	DFS(root);
	for (int q = 0; q < Q; q++){
		cin >> find;
		cout << DP[find] << '\n';
	}
}