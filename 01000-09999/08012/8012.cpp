// 8012 한동이는 영업사원!
// https://www.acmicpc.net/problem/8012
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> Village[30001];
int visit_order[5001], depth[30001];
int parent[30001][16];

void MakeTree(int v){
	int next;
	for (int i = 0; i < Village[v].size(); i++){
		next = Village[v][i];
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
	int v1, v2, answer = 0;
	cin >> N;
	for (int n = 0; n < N - 1; n++){
		cin >> v1 >> v2;
		Village[v1].push_back(v2);
		Village[v2].push_back(v1);
	}
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	depth[1] = 0;
	MakeTree(1);
	for (int j = 0; j < 16; j++){ // parent 배열 채우기
		for (int i = 2; i <= N; i++){
			if (parent[i][j] != -1){ // i번 노드가 j만큼 올라갔을 때에도 그 노드의 부모가 존재한다면
				parent[i][j + 1] = parent[parent[i][j]][j]; // 그 노드의 부모가 i번 노드가 j + 1만큼 올라갔을 때의 노드의 부모다
			}
		} 
	}
	cin >> M;
	for (int m = 0; m < M; m++){
		cin >> visit_order[m];
	}
	v1 = 1;
	for (int m = 0; m < M; m++){
		v2 = visit_order[m];
		if (v1 == v2){continue;}
		if (depth[v1] < depth[v2]){
			int tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		int diff = depth[v1] - depth[v2];
		int time_sum = 0, walk_time = 1;
		for (int k = 0; diff != 0; k++){
			if (diff % 2 == 1){
				v1 = parent[v1][k];
				time_sum += walk_time;
			}
			walk_time *= 2;
			diff /= 2;
		}
		walk_time = 1;
		for (int i = 0; i < 15; i++){walk_time *= 2;}
		if (v1 != v2){
			for (int k = 15; k >= 0; k--){
				if (parent[v1][k] != -1 && parent[v1][k] != parent[v2][k]){
					v1 = parent[v1][k];
					v2 = parent[v2][k];
					time_sum += (walk_time * 2);
				}
				walk_time /= 2;
			}
			v1 = parent[v1][0];
			time_sum += 2;
		}
		answer += time_sum;
		v1 = visit_order[m];
	}
	cout << answer;
}