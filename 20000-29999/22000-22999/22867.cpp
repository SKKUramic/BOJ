// 22867 종점
// https://www.acmicpc.net/problem/22867
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll HH, MM, SS, sss, t1, t2;

void maketime(string s){
	HH = (s[0] - '0') * 10 + s[1] - '0';
	MM = (s[3] - '0') * 10 + s[4] - '0';
	SS = (s[6] - '0') * 10 + s[7] - '0';
	sss = (s[9] - '0') * 100 + (s[10] - '0') * 10 + s[11] - '0';
	return;
}

bool cmp(pll a, pll b){
	if (a.first == b.first){return a.second < b.second;}
	return a.first < b.first;
}

struct pqcmp{
	bool operator()(pll a, pll b){
		if (a.second == b.second){return a.first > b.first;} // 필요없긴 함
		return a.second > b.second;
	}
};

vector<pll> bus;
priority_queue<pll, vector<pll>, pqcmp> pq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, answer = 0;
	string s;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> s;
		maketime(s);
		t1 = sss + SS * 1000 + MM * 60000 + HH * 3600000;
		cin >> s;
		maketime(s);
		t2 = sss + SS * 1000 + MM * 60000 + HH * 3600000;
		bus.push_back({t1, t2});
	}
	sort(bus.begin(), bus.end(), cmp);
	for (int n = 0; n < N; n++){
		while (!pq.empty()){
			if (pq.top().second <= bus[n].first){pq.pop();}
			else {break;}
		}
		pq.push(bus[n]);
		if (answer < pq.size()){answer = pq.size();}
	}
	cout << answer;
}