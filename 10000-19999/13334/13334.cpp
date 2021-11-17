// 13334 철로
// https://www.acmicpc.net/problem/13334
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> line;
priority_queue<ll, vector<ll>, greater<ll>> pq;

bool cmp(pll a, pll b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pll L;
	int people, maxcnt = 0;
	ll Length;
	cin >> people;
	for (int p = 0; p < people; p++){
		cin >> L.first >> L.second;
		if (L.first > L.second){
			ll temp = L.first;
			L.first = L.second;
			L.second = temp;
		}
		line.push_back(L);
	}
	cin >> Length;
	sort(line.begin(), line.end(), cmp);
	for (int p = 0; p < people; p++){
		if (line[p].second - line[p].first <= Length){
			pq.push(line[p].first);
		}
		else {continue;}
		while (!pq.empty()){
			ll temp = pq.top();
			if (line[p].second - temp <= Length){break;}
			pq.pop();
		}
		if (maxcnt < pq.size()){maxcnt = pq.size();}
	}
	cout << maxcnt;
}