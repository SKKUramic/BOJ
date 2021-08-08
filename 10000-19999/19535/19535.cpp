// 19535 ㄷㄷㄷㅈ
// https://www.acmicpc.net/problem/19535
// D-트리: (나와 연결된 노드의 수 - 1) * (나와 연결된 노드와 연결된 노드의 수 - 1)의 총합의 절반, 서로 연결된 것은 세지 않으며 모든 D-트리는 두 번 세어지기 떄문이다.
// G-트리: (자기와 연결된 노드의 수)C(3)의 총합
#include <iostream>
#include <vector>
using namespace std;

vector<int> dddg_tree[300001];
long long int D = 0, G = 0;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node_count, node1, node2, size;
	cin >> node_count;
	for (int i = 0; i < node_count - 1; i++){
		cin >> node1 >> node2;
		dddg_tree[node1].push_back(node2);
		dddg_tree[node2].push_back(node1);
	}
	for (int i = 1; i <= node_count; i++){
		size = dddg_tree[i].size(); // 여러 번 호출하지 않기 위해 변수에 저장
		if (size == 0) {continue;} // 연결되어있지 않은 노드이면 그냥 스킵(없을 거 같지만)
		if (size >= 3) {G += size * (size - 1) * (size - 2) / 6;}
		for (int k = 0; k < size; k++){
			D += (size - 1) * (dddg_tree[dddg_tree[i][k]].size() - 1);
		}
	}
	D /= 2; // 전부 다 세고 나면 모든 D-트리는 2번 세어져 있음
	if (D > 3 * G){
		cout << 'D';
	}
	else if (D < 3 * G){
		cout << 'G';
	}
	else { // ㄷㄷㄷㅈ
		cout << "DUDUDUNGA";
	}
}