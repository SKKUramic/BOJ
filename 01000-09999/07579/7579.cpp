// 7579 앱
// https://www.acmicpc.net/problem/7579
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

pair<int, int> App[101];
int DP[10010]; // DP[c]: c만큼 코스트를 썼을 때 확보한 최대 메모리

int RetMax(int a, int b){return a > b ? a : b;}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, cost_sum = 0, answer_cost;
	memset(DP, -1, sizeof(DP));
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		cin >> App[n].second;
	}
	for (int n = 0; n < N; n++){
		cin >> App[n].first;
		cost_sum += App[n].first;
	}
	sort(App, App + N);
	DP[0] = 0;
	for (int n = 0; n < N; n++){
		for (int idx = cost_sum; idx >= 0; idx--){
			if (DP[idx] != -1 && idx + App[n].first <= cost_sum){
				DP[idx + App[n].first] = RetMax(DP[idx + App[n].first], DP[idx] + App[n].second);
			}
		}
	}
	
	for (int idx = 0; idx <= cost_sum; idx++){
		if (DP[idx] >= M){
			answer_cost = idx;
			break;
		}
	}
	cout << answer_cost;
}