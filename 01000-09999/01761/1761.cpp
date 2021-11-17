// 1761 정점들의 거리
// https://www.acmicpc.net/problem/1761
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii; // v2, length

int parent[40002][20]; // 현재 노드로부터 depth + 1만큼 올라가면 나오는 부모를 저장함, [현재 노드][depth]
pii depth[40002]; // 루트 노드로부터 얼마나 떨어져 있는가<깊이, 길이>
vector<pii> Tree[40002];

void MakeTree(int v){
	int next;
	for (int i = 0; i < Tree[v].size(); i++){
		next = Tree[v][i].first;
		if (depth[next].first == -1){
			parent[next][0] = v; // 다음 노드의 부모는 v
			depth[next].first = depth[v].first + 1; // 다음 노드의 깊이는 (v의 깊이 + 1)
			depth[next].second = depth[v].second + Tree[v][i].second;
			MakeTree(next);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, v1, v2, N, M, Length;
	cin >> N;
	for (int n = 0; n < N - 1; n++){
		cin >> v1 >> v2 >> Length;
		Tree[v1].push_back({v2, Length});
		Tree[v2].push_back({v1, Length});
	}
	for (int x = 0; x <= 40000; x++){
		for (int y = 0; y < 20; y++){parent[x][y] = -1;}
		depth[x].first = -1; depth[x].second = -1;
	}
	memset(parent, -1, sizeof(parent));
	for (int n = 0; n <= N; n++){depth[n].first = -1; depth[n].second = -1;}
	depth[1].first = 0; depth[1].second = 0;
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
		int len = 0;
		cin >> v1 >> v2;
		if (depth[v1].first < depth[v2].first){
			int tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		int diff = depth[v1].first - depth[v2].first;
		len = depth[v1].second + depth[v2].second;
		for (int k = 0; diff != 0; k++){ // 높이 차를 없애서 동일한 높이에 위치시킴
			if (diff % 2 == 1){
				v1 = parent[v1][k];
			}
			diff /= 2;
		}
		while (v1 != v2){ 
			for (int j = 15; j >= 0; j--){
				if (parent[v1][j] != -1 && parent[v1][j] != parent[v2][j]){ // 일단 부모가 있고, v1과 v2의 최소 공통 조상에 아직 도달하지 못했다면
					v1 = parent[v1][j];
					v2 = parent[v2][j];
				}
			}
			v1 = parent[v1][0];
			v2 = parent[v2][0];
		}
		len -= (depth[v1].second + depth[v2].second); // v1 = v2
		cout << len << '\n';
	}
}