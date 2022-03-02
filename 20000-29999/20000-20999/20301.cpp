// 20301 반전 요세푸스
// https://www.acmicpc.net/problem/20301
#include <iostream>
#include <deque>
using namespace std;

deque<int> Josephus;

int main(){
	int N, K, M, M_count = 0;
	bool clockwise = true;
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++){
		Josephus.push_back(i);
	}
	while (!Josephus.empty()){
		if (M_count == M){
			clockwise = !clockwise;
			M_count = 0;
		}
		if (clockwise == true){
			for (int i = 0; i < K - 1; i++){
				Josephus.push_back(Josephus.front());
				Josephus.pop_front();
			}
			cout << Josephus.front() << '\n';
			Josephus.pop_front();
		}
		else {
			for (int i = 0; i < K - 1; i++){
				Josephus.push_front(Josephus.back());
				Josephus.pop_back();
			}
			cout << Josephus.back() << '\n';
			Josephus.pop_back();
		}
		M_count++;
	}
}