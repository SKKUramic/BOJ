// 13913 숨바꼭질 4
// https://www.acmicpc.net/problem/13913
// 1697 숨바꼭질의 코드를 변형시켰습니다. 시작점 = 도착점 예외를 제대로 처리를 안 해서 OutofBounds 에러를 엄청나게 당한 뼈아픈 문제였습니다ㅠㅠ
#include <iostream>
#include <queue>
using namespace std;

int room[100010] = {0, };
int answer_arr[100010] = {0, };
bool visit_room[100010] = {false, };

int BFS(int start, int end){
	if (start == end){return 0;} // 이미 도달했다면 0초 반환
	queue <int> q;
	int s, second = 0, times = 1, count;
	visit_room[start] = true;
	q.push(start);
	while (1){
		second++;
		count = 0;
		for (int i = 0; i < times; i++){
			s = q.front();
			q.pop();
			if (s - 1 == end || s + 1 == end || 2 * s == end){ // 목적지에 도달할 수 있으면 시간 반환
				if (s - 1 == end){
					room[s - 1] = s;
				}
				else if (s + 1 == end){
					room[s + 1] = s;
				}
				else if (2 * s == end){
					room[2 * s] = s;
				}
				return second;
			} // 이하의 코드는 간 적 없는 방에 대해서만 검사하며, 큐에 있는 원소를 세기 위해 임시 변수인 count 사용
			if (s > 0 && visit_room[s - 1] == false){
				visit_room[s - 1] = true;
				room[s - 1] = s; // minus
				q.push(s - 1);
				count++;
			}
			if (s < 100000 && visit_room[s + 1] == false){
				visit_room[s + 1] = true;
				room[s + 1] = s; // plus
				q.push(s + 1);
				count++;
			}
			if (s <= 50000 && visit_room[2 * s] == false){
				visit_room[2 * s] = true;
				room[2 * s] = s; // multiple
				q.push(2 * s);
				count++;
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
	room[here] = -1; // 목적지
	answer = BFS(here, destination);
	cout << answer << '\n';
	int go_idx = 0;
	int idx = destination;
	while (room[idx] != -1){ // 역순으로 돌아가면서 출력할 숫자들을 stack에 넣음
		answer_arr[go_idx++] = idx;
		idx = room[idx];
	}
	answer_arr[go_idx] = here; // 코드상 이 때의 go_idx는 반드시 answer이다
	for (int i = go_idx; i >= 0; i--){
		cout << answer_arr[i];
		if (i != 0){cout << ' ';}
	}
}