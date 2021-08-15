// 1202 보석 도둑
// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll bag[300001];
pll jewel[300001];
priority_queue<ll, vector<ll>> can_steal;

int main(){
	int N, K;
	cin >> N >> K;
	for (int n = 0; n < N; n++){
		cin >> jewel[n].first >> jewel[n].second;
	}
	for (int k = 0; k < K; k++){
		cin >> bag[k];
	}
	sort(jewel, jewel + N); // 무게가 작은 순서대로 정렬
	sort(bag, bag + K); // 가방 용량이 작은 순서대로 정렬
	ll answer = 0;
	int idx = 0;
	for (int k = 0; k < K; k++){
		while (idx < N && bag[k] >= jewel[idx].first){ // bag[k]가 넣을 수 있는 보석들을 다 우선순위 큐에 넣음, 다음 가방들도 이 보석들을 넣을 수 있음
			can_steal.push(jewel[idx++].second);
		}
		if (!can_steal.empty()){
			answer += can_steal.top();
			can_steal.pop(); // 이미 가방에 넣은 보석은 제외
		}
	}
	cout << answer;
}