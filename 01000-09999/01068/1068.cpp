// 1068 트리
// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>
using namespace std;

bool visited[51];
vector<int> Tree[51];
int N, root, ban, ans = 0;

void DFS(int v){
	visited[v] = true;
	int next, cnt = 0;
	for (int i = 0; i < Tree[v].size(); i++){
		next = Tree[v][i];
		if (next == ban){continue;}
		if (visited[next] == false){
			cnt++;
			DFS(next);
		}
	}
	if (cnt == 0){ans++;}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> node;
		if (node == -1){root = n;}
		else {
			Tree[node].push_back(n);
			Tree[n].push_back(node);
		}
	}
	cin >> ban;
	if (root == ban){
		cout << 0;
		return 0;
	}
	DFS(root);
	cout << ans;
}