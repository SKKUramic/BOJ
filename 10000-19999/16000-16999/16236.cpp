// 16236 아기 상어
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define DEBUG 0

int side;
int shark_count = 0;
int shark_size = 2;
int shark_eat_fish = 0;
bool visited[21][21];
bool break_flag = true;
int SEA[21][21];
int fish_count = 0;
pair<int, int> shark_pos;

struct cmp{
	bool operator()(pair<int, int> a, pair<int, int> b){
		if (a.first == b.first){
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void init_visited(){
	for (int i = 0; i < 21; i++){
		for (int j = 0; j < 21; j++){
			visited[i][j] = false;
		}
	}
	return;
}

int find_shortest_path(){
	bool eat_fish = false;
	break_flag = false;
	int time = 0, v_size;
	pair<int, int> s;
	queue<pair<int, int>> q;
	init_visited();
	pq.push(shark_pos);
	visited[shark_pos.first][shark_pos.second] = true;
	#if DEBUG
	cout << "start point: " << shark_pos.first << ',' << shark_pos.second << '\n';
	cout << "shark_size: " << shark_size << ", shark_eat_fish: " << shark_eat_fish << ", shark_count: " << shark_count << '\n';
	#endif
	while (!pq.empty() && !eat_fish){
		while (!pq.empty()){
			q.push(pq.top());
			pq.pop();
		}
		while (!q.empty()){
			s = q.front();
			q.pop();
			#if DEBUG
			cout << "time: " << time << ' ' << s.first << ' ' << s.second << '\n';
			#endif
			if (SEA[s.first][s.second] < 7 && SEA[s.first][s.second] < shark_size && SEA[s.first][s.second] != 0){ // 이 자리에 먹을 물고기가 있다.(상어 아님ㅎ)
				#if DEBUG
				cout << "breaking at: " << s.first << ' ' << s.second << '\n';
				#endif
				SEA[s.first][s.second] = 9; // 이 곳에 있는 물고기는 이미 상어가 먹었다.
				SEA[shark_pos.first][shark_pos.second] = 0; // 이 곳에 있던 상어는 없어져 빈 공간이 됨
				shark_pos.first = s.first;	shark_pos.second = s.second; // 상어 위치 갱신
				shark_eat_fish++; //물고기 맛있게 먹었습니다.
				fish_count--;
				eat_fish = true;
				break_flag = true;
				break;
			} // 이 밑은 이 자리가 먹을 곳이 아닐 경우 발동됨
			if (s.first > 0 && visited[s.first - 1][s.second] == false){ // 위쪽
				if (SEA[s.first - 1][s.second] <= shark_size){ // 확인하는 칸이 이동 가능한 칸일 경우
					visited[s.first - 1][s.second] = true;
					pq.push({s.first - 1, s.second});
				}
			}
			if (s.second > 0 && visited[s.first][s.second - 1] == false){ // 왼쪽
				if (SEA[s.first][s.second - 1] <= shark_size){
					visited[s.first][s.second - 1] = true;
					pq.push({s.first, s.second - 1});
				}
			}
			if (s.second < side - 1 && visited[s.first][s.second + 1] == false){ // 오른쪽
				if (SEA[s.first][s.second + 1] <= shark_size){
					visited[s.first][s.second + 1] = true;
					pq.push({s.first, s.second + 1});
				}
			}
			if (s.first < side - 1 && visited[s.first + 1][s.second] == false){ // 아래쪽
				if (SEA[s.first + 1][s.second] <= shark_size){
					visited[s.first + 1][s.second] = true;
					pq.push({s.first + 1, s.second});
				}
			}
		}
		if (break_flag == false){
			time++;
		}
	}
	while (!pq.empty()){pq.pop();} // 일 다했다^^
	if (break_flag == true){
		return time;
	}
	else {
		return 0;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int pq_size, time_passed = 0;
	cin >> side;
	for (int i = 0; i < side; i++){
		for (int j = 0; j < side; j++){
			cin >> SEA[i][j];
			if (SEA[i][j] != 0){
				if (SEA[i][j] == 9){
					shark_pos.first = i;
					shark_pos.second = j;
				}
				else {
					fish_count++;
				}
			}
			
		}
	}
	while (fish_count != 0 && break_flag == true){
		time_passed += find_shortest_path();
		shark_count++;
		if (shark_eat_fish == shark_size){
			shark_size++;
			shark_eat_fish = 0;
		}
		#if DEBUG
		cout << "cur_time_passed: " << time_passed << '\n' << '\n';
		#endif
	}
	cout << time_passed;
}