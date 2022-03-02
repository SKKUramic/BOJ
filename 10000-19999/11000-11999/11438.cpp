// 11438 LCA 2
// https://www.acmicpc.net/problem/11438
// https://m.blog.naver.com/kks227/220820773477(라이 님의 블로그)에서 배웠습니다.
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100002][20]; // 현재 노드로부터 depth + 1만큼 올라가면 나오는 부모를 저장함, [현재 노드][depth]
int depth[100002]; // 루트 노드로부터 얼마나 떨어져 있는가
vector<int> Tree[100002];

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
	int TC, v1, v2, N, M;
	cin >> N;
	for (int n = 0; n < N - 1; n++){
		cin >> v1 >> v2;
		Tree[v1].push_back(v2);
		Tree[v2].push_back(v1);
	}
	memset(parent, -1, sizeof(parent));
	fill(depth, depth + (N + 1), -1);
	depth[1] = 0;
	MakeTree(1); // 문제 정의상 1이 루트 노드
	for (int j = 0; j < 19; j++){ // parent 배열 채우기
		for (int i = 2; i <= N; i++){
			if (parent[i][j] != -1){ // i번 노드가 j만큼 올라갔을 때에도 그 노드의 부모가 존재한다면
				parent[i][j + 1] = parent[parent[i][j]][j]; // 그 노드의 부모가 i번 노드가 j + 1만큼 올라갔을 때의 노드의 부모다
			}
		}
	}
	cin >> M;
	while (M-- > 0){
		cin >> v1 >> v2;
		if (depth[v1] < depth[v2]){ // 계산할 때 일관성이 있어야지
			int tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		int diff = depth[v1] - depth[v2];
		for (int k = 0; diff != 0; k++){ // 높이 차를 없애서 동일한 높이에 위치시킴
			if (diff % 2 == 1){v1 = parent[v1][k];}
			diff /= 2;
		}
		if (v1 != v2){ // 높이는 같지만 아직 부모가 다르면 둘 다 동시에 한 칸씩 올리면서 최소 공통 조상을 찾음
			for (int j = 18; j >= 0; j--){
				if (parent[v1][j] != -1 && parent[v1][j] != parent[v2][j]){ // 일단 부모가 있고, v1과 v2의 최소 공통 조상에 아직 도달하지 못했다면
					v1 = parent[v1][j];
					v2 = parent[v2][j];
				}
			}
			v1 = parent[v1][0]; // v1과 v2의 부모가 같아졌으므로, 그 둘의 부모를 v1에 저장
		}
		cout << v1 << '\n';
	}
}