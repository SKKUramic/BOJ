// 2161 카드1
// https://www.acmicpc.net/problem/2161
#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> q;
	int N;
	cin >> N;
	for (int n = 1; n <= N; n++){
		q.push(n);
	}
	while (!q.empty()){
		cout << q.front() << ' ';
		q.pop();
		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
	}
}