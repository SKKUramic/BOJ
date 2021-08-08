// 1158 요세푸스 문제
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>
using namespace std;

queue<int> Josephus;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		Josephus.push(i);
	}
	cout << '<';
	while (Josephus.size() > 1){
		for (int k = 0; k < K - 1; k++){
			Josephus.push(Josephus.front());
			Josephus.pop();
		}
		cout << Josephus.front() << ", ";
		Josephus.pop();
	}
	cout << Josephus.front() << '>';
}