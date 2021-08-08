// 1021 회전하는 큐
// https://www.acmicpc.net/problem/1021
#include <iostream>
#include <deque>
using namespace std;

#define debug 0

deque<int> d;
int arr[50];

int main(){
	int deque_size, M, idx, num, count = 0;
	cin >> deque_size >> M;
	for (int i = 1; i <= deque_size; i++){
		d.push_back(i); // 원소의 위치 = 원소의 값
	}
	for (int i = 0; i < M; i++){
		cin >> num;
		idx = 0;
		while(d[idx] != num){idx++;} // 빼야 하는 원소의 위치를 찾으러 감
		if (idx < d.size() - idx){ // 왼쪽으로 회전시키는 게 이득일 때
			while(d.front() != num){
				d.push_back(d.front());
				d.pop_front();
				count++;
			}
			d.pop_front();
		}
		else { // 오른쪽으로 회전시키는 게 이득일 때
			while (d.front() != num){
				d.push_front(d.back());
				d.pop_back();
				count++;
			}
			d.pop_front();
		}
		#if debug
		cout << "idx: " << idx << '\n';
		cout << "current_count: " << count << '\n';
		for (int i = 0; i < d.size(); i++){
			cout << d[i] << ' ';
		}
		cout << '\n';
		#endif
	}
	cout << count;
}