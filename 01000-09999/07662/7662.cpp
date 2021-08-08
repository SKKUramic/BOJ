// 7662 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662
// https://jaimemin.tistory.com/997의 코드입니다. 정말 많이 배웠습니다.
#include <iostream>
#include <queue>
using namespace std;

bool visit[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, Tpq, temp, idx;
	char c;
	cin >> T;
	for (int i = 0; i < T; i++){
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> small_to_big; //123456
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> big_to_small; //654321
		cin >> Tpq;
		for (int j = 0; j < Tpq; j++){
			cin >> c >> temp;
			if (c == 'I'){
				big_to_small.push({temp, j});
				small_to_big.push({temp, j});
				visit[j] = true;
			}
			// 다른 큐에서 이미 빠진 값이 이 큐에서는 빠져 있지 않을 수 있다. 그 경우를 배제하기 위해 값을 뺄 때 그 값이 유효하지 않게 한다.
			// 이후 유효하지 않은 값에 의해 잘못 되는 과정을 막기 위해, 큐의 탑 원소가 유효하지 않을 경우 반드시 제거하도록 한다.
			// 그러면 유효한 값에 대해서만 검사를 하게 될 것이다.
			else { // c == 'D'
				if (temp == -1){
					while (!small_to_big.empty() && !visit[small_to_big.top().second]){
						small_to_big.pop();
					}
					
					if (!small_to_big.empty()){
						visit[small_to_big.top().second] = false;
						small_to_big.pop();
					}/*
					big_to_small.pop();
					int arr[100001];
					idx = 0;
					while (!small_to_big.empty()){
						arr[idx++] = small_to_big.top();
						small_to_big.pop();
					}
					for (int i = 0; i < idx - 1; i++){
						small_to_big.push(arr[i]);
					}*/
					// 이 코드는 그냥 반대쪽 큐의 원소를 싹 다 빼서 맨 아래 값을 빼는 방법이다.
					// 이 방법은 시간 초과에 걸린다.
				}
				else if (temp == 1){
					while (!big_to_small.empty() && !visit[big_to_small.top().second]){
						big_to_small.pop();
					}
					if (!big_to_small.empty()){
						visit[big_to_small.top().second] = false;
						big_to_small.pop();
					}/*small_to_big.pop();
					int arr[100001];
					idx = 0;
					while (!big_to_small.empty()){
						arr[idx++] = big_to_small.top();
						big_to_small.pop();
					}
					for (int i = 0; i < idx - 1; i++){
						big_to_small.push(arr[i]);
					}*/
				}
			}
		}
		while (!small_to_big.empty() && !visit[small_to_big.top().second]){
			small_to_big.pop();
		}
		while (!big_to_small.empty() && !visit[big_to_small.top().second]){
			big_to_small.pop();
		}
		if (small_to_big.empty() == true && big_to_small.empty() == true){
			printf("EMPTY\n");
		}
		else {
			printf("%d %d\n", big_to_small.top().first, small_to_big.top().first);
		}
	}
}