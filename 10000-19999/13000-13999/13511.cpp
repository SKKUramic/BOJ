// 13511 트리와 쿼리 2
// https://www.acmicpc.net/problem/13511
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> pll; // v2, length

int parent[100002][20]; // 현재 노드로부터 2^depth만큼 올라가면 나오는 부모를 저장함, [현재 노드][depth]
int depth[100002]; // 루트 노드로부터 얼마나 떨어져 있는가
long long road_Length[100002];
vector<pll> Tree[100002];
int depth_diff, parents;

void MakeTree(int v){
	int next;
	for (int i = 0; i < Tree[v].size(); i++){
		next = Tree[v][i].first;
		if (depth[next] == -1){
			parent[next][0] = v; // 다음 노드의 부모는 v
			depth[next] = depth[v] + 1; // 다음 노드의 깊이는 (v의 깊이 + 1)
			road_Length[next] += Tree[v][i].second + road_Length[v];
			MakeTree(next);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v1, v2, N, M, command, L, K;
	cin >> N;
	for (int n = 0; n < N - 1; n++){
		cin >> v1 >> v2 >> L;
		Tree[v1].push_back({v2, L});
		Tree[v2].push_back({v1, L});
	}
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	depth[1] = 0;
	MakeTree(1);
	for (int j = 0; j < 18; j++){ // parent 배열 채우기
		for (int i = 2; i <= N; i++){
			if (parent[i][j] != -1){ // i번 노드가 j만큼 올라갔을 때에도 그 노드의 부모가 존재한다면
				parent[i][j + 1] = parent[parent[i][j]][j]; // 그 노드의 부모가 i번 노드가 j + 1만큼 올라갔을 때의 노드의 부모다
			}
		} 
	}
	cin >> M;
	while (M-- > 0){
		cin >> command >> v1 >> v2;
		int tmp_v1 = v1, tmp_v2 = v2;
		// LCA 찾기
		if (depth[v1] < depth[v2]){
			int tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		int diff = depth[v1] - depth[v2];
		for (int k = 0; diff != 0; k++){
			if (diff % 2 == 1){v1 = parent[v1][k];}
			diff /= 2;
		}
		if (v1 != v2){
			for (int k = 18; k >= 0; k--){
				if (parent[v1][k] != -1 && parent[v1][k] != parent[v2][k]){
					v1 = parent[v1][k];
					v2 = parent[v2][k];
				}
			}
			v1 = parent[v1][0];
		}
		// 쿼리 수행
		if (command == 1){
			long long Length = road_Length[tmp_v1] + road_Length[tmp_v2] - 2 * road_Length[v1];
			cout << Length << '\n';
		}
		else if (command == 2){
			cin >> K;
			int step = depth[tmp_v1] - depth[v1] + 1; // v1에서 LCA까지 거치는 노드
			if (step == K){cout << v1 << '\n';} // LCA가 답
			else if (K < step){ // v1에서 LCA로 가는 경로 중에 있음
				K--;
				for (int k = 18; k >= 0; k--){
					if ((K & (1 << k)) != 0){ // (1 << k)만큼 올라가야 한다면
						tmp_v1 = parent[tmp_v1][k]; // 그만큼 올라감
						K -= (1 << k); // 올라간 만큼 뺌
					}
				}
				cout << tmp_v1 << '\n';
			}
			else { // LCA에서 v2로 가는 경로 중에 있음
				K -= step; // 앞으로 갈 노드를 저장
				K = (depth[tmp_v2] - depth[v1]) - K; // v2에서 LCA로 올라가야 할 노드의 수를 정정함
				for (int k = 18; k >= 0; k--){
					if ((K & (1 << k)) != 0){
						tmp_v2 = parent[tmp_v2][k];
						K -= (1 << k);
					}
				}
				cout << tmp_v2 << '\n';
			}
		}
	}
}