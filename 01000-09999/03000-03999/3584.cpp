// 3584 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
vector<int> Tree[10001];
int depth[10001], isroot[10001];
int parent[10001][16];

void MakeTree(int v){
	int next;
	for (int i = 0; i < Tree[v].size(); i++){
		next = Tree[v][i];
		if (depth[next] == -1){
			parent[next][0] = v; // 다음 노드의 부모는 v
			depth[next] = depth[v] + 1; // 다음 노드의 깊이는 (v의 깊이 + 1)
			MakeTree(next);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, root;
	int v1, v2;
	cin >> TC;
	while (TC-- > 0){
		memset(isroot, 0, sizeof(isroot));
		memset(depth, -1, sizeof(depth));
		memset(parent, -1, sizeof(parent));
		cin >> N;
		for (int n = 0; n < N - 1; n++){
			cin >> v1 >> v2;
			Tree[v1].push_back(v2);
			Tree[v2].push_back(v1);
			isroot[v2]++;
		}
		for (int n = 1; n <= N; n++){
			if (isroot[n] == 0){
				root = n;
				break;
			}
		}
		depth[root] = 0;
		MakeTree(root);
		for (int j = 0; j < 15; j++){
			for (int i = 1; i <= N; i++){
				if (i == root){continue;}
				if (parent[i][j] != -1){
					parent[i][j + 1] = parent[parent[i][j]][j];
				}
			}
		}
		cin >> v1 >> v2;
		if (depth[v1] < depth[v2]){
			int tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		int diff = depth[v1] - depth[v2];
		for (int k = 0; diff != 0; k++){
			if (diff % 2 == 1){
				v1 = parent[v1][k];
			}
			diff /= 2;
		}
		if (v1 != v2){
			for (int k = 15; k >= 0; k--){
				if (parent[v1][k] != -1 && parent[v1][k] != parent[v2][k]){
					v1 = parent[v1][k];
					v2 = parent[v2][k];
				}
			}
			v1 = parent[v1][0];
		}
		cout << v1 << '\n';
		for (int n = 1; n <= N; n++){Tree[n].clear();}
	}
}