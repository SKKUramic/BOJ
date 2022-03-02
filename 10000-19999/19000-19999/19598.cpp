// 19598 최소 회의실 개수
// https://www.acmicpc.net/problem/19598
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool cmp(pll a, pll b){
	if (a.first == b.first){return a.second < b.second;}
	return a.first < b.first;
}

struct pqcmp{
	bool operator()(pll a, pll b){
		if (a.second == b.second){return a.first > b.first;} // 종료시간이 같으면 시작 시간이 늦은 순으로
		return a.second > b.second; // 종료시간이 늦은 순으로 정렬 -> top에는 가장 먼저 끝나는 게 옴
	}
};

vector<pll> room;
priority_queue<pll, vector<pll>, pqcmp> pq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pll C;
	int N, answer = 0;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> C.first >> C.second;
		room.push_back(C);
	}
	sort(room.begin(), room.end(), cmp);
	for (int n = 0; n < N; n++){
		while (!pq.empty()){
			if (pq.top().second <= room[n].first){pq.pop();}
			else {break;}
		}
		pq.push(room[n]);
		if (answer < pq.size()){answer = pq.size();}
	}
	cout << answer;
}