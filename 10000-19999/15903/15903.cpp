// 15903 카드 합체 놀이
// https://www.acmicpc.net/problem/15903
#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int card, fusion, card_number, a, b;
	long long int answer = 0;
	cin >> card >> fusion;
	for (long long int i = 0; i < card; i++){
		cin >> card_number;
		pq.push(card_number);
	}
	for (long long int i = 0; i < fusion; i++){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	while (!pq.empty()){
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}