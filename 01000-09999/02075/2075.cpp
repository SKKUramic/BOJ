// 2075 N번째 큰 수
// https://www.acmicpc.net/problem/2075
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
	bool operator()(int a, int b){return a > b;}
};

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	priority_queue<int, vector<int>, cmp> pq;
	cin >> N;
	for (int n = 0; n < N * N; n++){
		cin >> num;
		pq.push(num);
		if (pq.size() > N){pq.pop();}
	}
	cout << pq.top();
}