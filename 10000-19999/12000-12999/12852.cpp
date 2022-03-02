// 12852 1로 만들기 2
// https://www.acmicpc.net/problem/12852
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
pair<int, int> dp[1000001]; // <past_idx, time>
pair<int, int> temp;
int visit[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, idx = 1, visit_idx = 0;
	cin >> N;
	dp[N] = {-1, 0};
	q.push({N, 0});
	while (!q.empty()){
		temp = q.front();
		q.pop();
		if (temp.first == 1){break;}
		if (temp.first % 3 == 0){
			if (dp[temp.first / 3].first == 0){
				dp[temp.first / 3] = {temp.first, temp.second + 1};
				q.push({temp.first / 3, temp.second + 1});
			}
			else {
				if (dp[temp.first / 3].second > temp.second + 1){
					dp[temp.first / 3] = {temp.first, temp.second + 1};
					q.push({temp.first / 3, temp.second + 1});
				}
			}
		}
		if (temp.first % 2 == 0){
			if (dp[temp.first / 2].first == 0){
				dp[temp.first / 2] = {temp.first, temp.second + 1};
				q.push({temp.first / 2, temp.second + 1});
			}
			else {
				if (dp[temp.first / 2].second > temp.second + 1){
					dp[temp.first / 2] = {temp.first, temp.second + 1};
					q.push({temp.first / 2, temp.second + 1});
				}
			}
		}
		if (dp[temp.first - 1].first == 0){
			dp[temp.first - 1] = {temp.first, temp.second + 1};
			q.push({temp.first - 1, temp.second + 1});
		}
		else {
			if (dp[temp.first - 1].second > temp.second + 1){
				dp[temp.first - 1] = {temp.first, temp.second + 1};
				q.push({temp.first - 1, temp.second + 1});
			}
		}
	}
	cout << dp[1].second << '\n';
	while (dp[idx].first != -1){
		visit[visit_idx++] = idx;
		idx = dp[idx].first;
	}
	visit[visit_idx] = N;
	for (int i = visit_idx; i >= 0; i--){
		cout << visit[i];
		if (i != 0){cout << ' ';}
	}
	
}