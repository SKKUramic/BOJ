// 15708 미네크래프트
// https://www.acmicpc.net/problem/15708
#include <iostream>
#include <queue>
using namespace std;

long long stone[100001];
long long N, T, P, cost = 0;
int answer = 0;
priority_queue<long long> pq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> T >> P;
	for (int n = 0; n < N; n++){
		cin >> stone[n];
	}
	for (int n = 0; n < N; n++){
		pq.push(stone[n]);
		cost += stone[n];
		if (cost > T){ // 이것까지 캐면 시간 부족
			cost -= pq.top();
			pq.pop();
		}
		else {
			if (answer < pq.size()){
				answer = pq.size();
			}
		}
		cost += P; // 이동
	}
	cout << answer;
}