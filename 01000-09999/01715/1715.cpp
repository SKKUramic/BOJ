// 1715 카드 정렬하기
// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Small{
	bool operator()(long long a, long long b){
		return a > b;
	}
};

priority_queue<long long, vector<long long>, Small> Smallpq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long num, a, b, time = 0;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		Smallpq.push(num);
	}
	while (Smallpq.size() > 1){
		a = Smallpq.top(); Smallpq.pop();
		b = Smallpq.top(); Smallpq.pop();
		time += (a + b);
		Smallpq.push(a + b);
	}
	cout << time;
}