// 2643 색종이 올려놓기
// https://www.acmicpc.net/problem/2643
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> origami; // 큰 변이 왼쪽에 저장됨
int dp[101] = {0, };

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first){
		return a.second >= b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int paper, a, b, ans;
	cin >> paper;
	for (int p = 0; p < paper; p++){
		cin >> a >> b;
		if (a > b){
			origami.push_back({a, b});
		}
		else {
			origami.push_back({b, a});
		}
	}
	sort(origami.begin(), origami.end(), cmp);
	for (int i = 0; i < paper; i++){dp[i] = 1;}
	ans = 1;
	for (int i = 1; i < paper; i++){
		for (int idx = 0; idx < i; idx++){
			if (origami[idx].first >= origami[i].first && origami[idx].second >= origami[i].second){
				dp[i] = max(dp[idx] + 1, dp[i]);
			}
		}
		ans = max(ans, dp[i]); // 앞으로 종이를 추가하지 못할지도 모르니 답 갱신
	}
	cout << ans;
}