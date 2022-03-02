// 12851 숨바꼭질 2
// https://www.acmicpc.net/problem/12851
// 1697 숨바꼭질 코드의 개량판입니다.
#include <iostream>
#include <queue>
using namespace std;

int room[100001] = {0, };
int visit_count[100001] = {0, }; // 이 방에 방문가능한 경우가 몇 가지인지 저장
int visit_time[100001] = {0, }; // 이 방에 방문한 최소 시간이 언제인지 저장
bool visit_room[100001] = {false, };
bool break_flag = false;
int ways = 0;

int BFS(int start, int end){
	if (start == end){
		ways = 1; // 가만히 있는 방법 하나
		return 0;
	} // 이미 도달했다면 0초 반환
	queue <int> q;
	int s, second = 0, times = 1, count;
	visit_room[start] = true;
	visit_count[start] = 1;
	q.push(start);
	while (!break_flag){
		second++;
		count = 0;
		for (int i = 0; i < times; i++){
			s = q.front();
			q.pop();
			if (s - 1 == end || s + 1 == end || 2 * s == end){ // 목적지에 도달할 수 있으면 시간 반환
				break_flag = true;
				ways += visit_count[s];
				//return second;
			} // 이하의 코드는 간 적 없는 방에 대해서만 검사하며, 큐에 있는 원소를 세기 위해 임시 변수인 count 사용
			if (s > 0){
				if (visit_room[s - 1] == false){ // 이 방에 최초 방문한 경우일 경우
					visit_room[s - 1] = true;
					q.push(s - 1);
					count++;
					visit_count[s - 1] += visit_count[s];
					visit_time[s - 1] = second;
				}
				else if (visit_time[s - 1] == second){ // 같은 시간에 방문했을 경우에만 경우의 수를 더함
					visit_count[s - 1] += visit_count[s];
				}
			}
			if (s < 100000){
				if (visit_room[s + 1] == false){ // 이 방에 최초 방문한 경우일 경우
					visit_room[s + 1] = true;
					q.push(s + 1);
					count++;
					visit_count[s + 1] += visit_count[s];
					visit_time[s + 1] = second;
				}
				else if (visit_time[s + 1] == second){ // 같은 시간에 방문했을 경우에만 경우의 수를 더함
					visit_count[s + 1] += visit_count[s];
				}
			}
			if (s <= 50000){
				if (visit_room[2 * s] == false){ // 이 방에 최초 방문한 경우일 경우
					visit_room[2 * s] = true;
					q.push(2 * s);
					count++;
					visit_count[2 * s] += visit_count[s];
					visit_time[2 * s] = second;
				}
				else if (visit_time[2 * s] == second){ // 같은 시간에 방문했을 경우에만 경우의 수를 더함
					visit_count[2 * s] += visit_count[s];
				}
			}
		}
		times = count;
	}
	return second;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int here, destination, answer;
	cin >> here >> destination;
	answer = BFS(here, destination);
	cout << answer << '\n' << ways;
}