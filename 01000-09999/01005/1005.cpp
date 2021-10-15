// 1005 ACM Craft
// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Builds, BuildRules, GoalBuild;
int RequireTime[1001], InDegree[1001], Result[1001], Answer[1001];
vector<int> Topology[1001];
int INF = 123456789;

int max(int a, int b){
	if (a >= INF){return b;}
	if (b >= INF){return a;}
	return a > b ? a : b;
}

void Initialize(){
	for (int i = 1; i <= 1000; i++){
		RequireTime[i] = 0;
		Result[i] = 0;
		InDegree[i] = 0;
		Answer[i] = INF;
		Topology[i].clear();
	}
	return;
}

void TopologySort(int N){
	queue<int> q;
	int x, y;
	for (int n = 1; n <= N; n++){
		if (InDegree[n] == 0){
			q.push(n);
		}
	}
	for (int n = 1; n <= N; n++){
		if (q.empty()){return;}
		x = q.front();
		q.pop();
		Result[n] = x;
		for (int i = 0; i < Topology[x].size(); i++){
			y = Topology[x][i];
			if (--InDegree[y] == 0){
				q.push(y);
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, start, end, idx, cur_idx;
	cin >> TC;
	while (TC-- > 0){
		Initialize();
		cin >> Builds >> BuildRules;
		for (int n = 1; n <= Builds; n++){cin >> RequireTime[n];}
		for (int k = 0; k < BuildRules; k++){
			cin >> start >> end;
			Topology[start].push_back(end);
			InDegree[end]++;
		}
		cin >> GoalBuild;
		for (int in = 1; in <= Builds; in++){
			if (InDegree[in] == 0){Answer[in] = RequireTime[in];} // 최초 건물들의 소요 시간 = 건물 짓는 시간
		}
		TopologySort(Builds); // 건물을 짓는 순서를 위상정렬함
		for (int n = 1; n <= Builds; n++){
			idx = Result[n]; // 이 건물이 걸리는 시간을 조사
			for (int k = 0; k < Topology[idx].size(); k++){
				cur_idx = Topology[idx][k];
				Answer[cur_idx] = max(Answer[cur_idx], Answer[idx] + RequireTime[cur_idx]); // min(현재 최솟값, 지금까지 걸린 시간 + 지금 짓는 건물 소요 시간)
			}
		}
		for (int r = 1; r <= Builds; r++){
			if (Answer[r] == INF){Answer[r] = RequireTime[r];} // r번 건물에 도달하는 경우가 없다면 최종 소요 시간 = 건물 짓는 시간
		}
		cout << Answer[GoalBuild] << '\n';
	}
}