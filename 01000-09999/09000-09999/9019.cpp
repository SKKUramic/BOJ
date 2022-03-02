// 9019 DSLR
// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<pair<int, string>> DSLR[10000];
queue<pair<int, string>> q;
bool inside_queue[10000];

void BFS(int start, int end){
	int q_size, count = 0;
	pair<int, string> p;
	while (!q.empty()){q.pop();}
	for (int i = 0; i < 10000; i++){inside_queue[i] = false;}
	q.push({start, ""});
	inside_queue[start] = true; // 방문한 숫자일 경우 다시는 방문 못 하게 함, 이미 방문한 숫자였다면 길이가 같거나 더 짧은 명령어로 갈 수 있었다는 게 이미 증명된 것이기 때문이다.
	while (!q.empty()){
		q_size = q.size();
		while (q_size-- > 0){
			p = q.front();
			q.pop();
			if (p.first == end){
				cout << p.second << '\n'; // 답을 찾은 경우에 곧바로 출력
				return;
			}
			for (int i = 0; i < 4; i++){
				if (inside_queue[DSLR[p.first][i].first] == false){ // 방문하지 않은 숫자에 대해서만 검사
					q.push(make_pair(DSLR[p.first][i].first, p.second + DSLR[p.first][i].second));
					inside_queue[DSLR[p.first][i].first] = true;
				}
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp, T, start, end;
	pair<int, string> P;
	for (int x = 0; x < 10000; x++){
		DSLR[x].push_back({(2 * x) % 10000, "D"});
		DSLR[x].push_back({(x + 9999) % 10000, "S"});
		DSLR[x].push_back({(x * 10) % 10000 + x / 1000, "L"});
		DSLR[x].push_back({(x / 10) + (x % 10) * 1000, "R"});
	}
	cin >> T;
	while (T-- > 0){
		cin >> start >> end;
		BFS(start, end);
	}
}