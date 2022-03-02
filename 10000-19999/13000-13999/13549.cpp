// 13549 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
// 1697 숨바꼭질 코드의 개량판입니다.
#include <iostream>
#include <queue>
using namespace std;

int room[100001] = {0, };
bool visit_room[100001] = {false, };

int BFS(int start, int end){
	if (start == end){return 0;} // 이미 도달했다면 0초 반환
	queue <int> q;
	int s, temp, second = 0, times = 1, count;
	visit_room[start] = true;
	q.push(start);
	while (start <= 50000 && start != 0){
		start *= 2;
		if (visit_room[start] == false){
			visit_room[start] = true;
			q.push(start);
			times++;
		}
	}
	while (1){
		second++;
		count = 0;
		for (int i = 0; i < times; i++){
			s = q.front();
			q.pop();
			if (s - 1 == end || s + 1 == end || 2 * s == end){ // 목적지에 도달할 수 있으면 시간 반환
				if (2 * s == end){ // 마지막 이동이 텔레포트일 경우, 1초 더한 것을 없앰
					return second - 1;
				}
				return second;
			} // 이하의 코드는 간 적 없는 방에 대해서만 검사하며, 큐에 있는 원소를 세기 위해 임시 변수인 count 사용
			if (s > 0 && visit_room[s - 1] == false){
				visit_room[s - 1] = true;
				q.push(s - 1);
				count++;
				temp = s - 1;
				while (temp <= 50000 && temp != 0){
					temp *= 2;
					if (visit_room[temp] == false){
						visit_room[temp] = true;
						q.push(temp);
						count++;
					}
				}
			}
			if (s < 100000 && visit_room[s + 1] == false){
				visit_room[s + 1] = true;
				q.push(s + 1);
				count++;
				temp = s + 1;
				while (temp <= 50000){
					temp *= 2;
					if (visit_room[temp] == false){
						visit_room[temp] = true;
						q.push(temp);
						count++;
					}
				}
			}
		}
		times = count;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int here, destination, answer;
	cin >> here >> destination;
	answer = BFS(here, destination);
	cout << answer;
}