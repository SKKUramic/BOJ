// 1766 문제집
// https://www.acmicpc.net/problem/1766
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int InDegree[33333] = {0, }; 
int result[33333] = {0, };
vector<int> topology[33333];

void topology_sort(int N){
	priority_queue<int, vector<int>, greater<int>> pq; // 문제 번호 순서로 풀어야 하므로
	for (int i = 1; i <= N; i++){
		if (InDegree[i] == 0){pq.push(i);}
	}
	for (int i = 1; i <= N; i++){
		if (pq.empty()){
			return;
		}
		int x = pq.top();
		pq.pop();
		result[i] = x;
		for (int i = 0; i < topology[x].size(); i++){
			int y = topology[x][i];
			if (--InDegree[y] == 0){ 
				pq.push(y);
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		topology[a].push_back(b);
		InDegree[b]++;
	}
	topology_sort(N);
	for (int i = 1; i <= N; i++){
		cout << result[i] << ' ';
	}
}