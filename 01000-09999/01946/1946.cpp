// 1946 신입 사원
// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, a, b, best_a, best_b, gotcha;
	cin >> T;
	while (T-- > 0){
		vector<pair<int, int>> newbie;
		gotcha = 1; // 일단 한 명은 뽑히니까
		cin >> N;
		while (N-- > 0){
			cin >> a >> b;
			newbie.push_back({a, b});
		}
		sort(newbie.begin(), newbie.end()); // 서류 심사 기준 정렬
		best_a = newbie[0].first;
		best_b = newbie[0].second;
		for (int i = 1; i < newbie.size(); i++){
			if (newbie[i].first < best_a || newbie[i].second < best_b){ // 지금 검사하는 사람보다 면접 심사를 잘 봤다면 기준을 지금 사람으로 바꿈
				best_a = newbie[i].first;
				best_b = newbie[i].second;
				gotcha++;
			}
		}
		cout << gotcha << '\n';
	}
}