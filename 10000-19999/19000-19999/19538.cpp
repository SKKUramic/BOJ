// 19538 루머
// https://www.acmicpc.net/problem/19538
// kth990303님의 코드를 보고 배웠습니다. 아직 BFS 사용이 미숙한가 봅니다.
// https://github.com/kth990303/Baekjoon/blob/master/19538_bfs.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, temp;
vector<int> neighbor[200001]; // 이 사람의 이웃이 누가 있는지
int rumor_believe_minute[200001]; // 이 사람이 언제 루머를 믿게 되었는지
int neighbor_believe_rumor[200001]; // 주변 이웃들 중 몇 명이나 믿는지
queue<pair<int, int>> neighborhood; // 루머를 믿게 된 사람과 그 시간을 저장

void print(){
	for (int i = 1; i <= N; i++){
		cout << rumor_believe_minute[i] << ' ';
	}
	cout << '\n';
}

void BFS(){
	int rumor_believe_person, believed_minute, half;
	while (!neighborhood.empty()){
		rumor_believe_person = neighborhood.front().first;
		believed_minute = neighborhood.front().second;
		rumor_believe_minute[rumor_believe_person] = believed_minute; // 새롭게 갱신해줌
		neighborhood.pop();
		for (auto idx : neighbor[rumor_believe_person]){ // rumor_believe_person의 모든 이웃들을 검사
			half = neighbor[idx].size() / 2 + neighbor[idx].size() % 2; // 절반의 기준
			if (rumor_believe_minute[idx] >= 0 || neighbor_believe_rumor[idx] >= half){ // 이 사람이 이미 루머를 믿거나, 이 사람 주변 사람의 절반 이상이 루머를 믿을 때 스킵
				continue;
			}
			if (rumor_believe_minute[rumor_believe_person] == believed_minute){ // rumor_believe_person이 바로 전에 믿게 있었을 경우, 새롭게 믿게 된 사람은 아님
				neighbor_believe_rumor[idx]++; // 이 사람의 이웃이 믿게 된 것과 같다
			}
			if (neighbor_believe_rumor[idx] >= half){ // 다시 물어보는데 이 이웃의 주변 사람의 절반 이상이 루머를 믿나요?
				neighbor_believe_rumor[rumor_believe_person]++; // rumor_believe_person의 이웃 하나가 루머를 믿게 되었으므로
				neighborhood.push({idx, believed_minute + 1}); // 드디어 이웃이 루머를 믿게 되었습니다 여러분
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++){
		rumor_believe_minute[i] = -1;
		cin >> temp;
		while (temp != 0){
			neighbor[i].push_back(temp);
			cin >> temp;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> temp;
		rumor_believe_minute[temp] = 0;
		neighborhood.push({temp, 0});
	}
	BFS();
	print();
}


// 이하의 내용은 틀린 코드입니다. 제 습작으로 그냥 기록해 두었습니다...ㅠㅠ


/*
// 19538 루머
// https://www.acmicpc.net/problem/19538
// https://seongjuk.tistory.com/entry/2020-UCPC-%EC%98%88%EC%84%A0-%ED%9B%84%EA%B8%B0-1를 참조했습니다.
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

queue<pair<int, int>> neighborhood;
vector<int> relations[200001]; // idx번째 사람의 지인 목록
int rumor_believe[200001] = {0, }; // idx번째 사람이 루머를 믿는지의 여부
int relations_people[200001] = {0, }; // idx번째 사람의 지인 수
queue<int> gonna_believe_rumor; // 루머를 믿게 되버린 사람들을 저장하는 큐

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int human, human_count, neighbor, rumor_believe_human, rumor_start, relations_count;
	int node, minute, count, current_neighbor, another_neighbor;
	cin >> human_count; // 사람 수
	for (int i = 1; i <= human_count; i++){ // 모든 사람이 루머를 믿지 않는다고 가정
		rumor_believe[i] = -1;
	}
	for (human = 1; human <= human_count; human++){
		relations_count = 0;
		cin >> neighbor;
		while (neighbor != 0){ // human번째 사람의 지인을 입력받음
			relations_count++;
			relations[human].push_back(neighbor);
			cin >> neighbor;
		}
		relations_people[human] = relations_count;
	}
	cin >> rumor_believe_human; // 루머를 믿는 사람의 수
	for (human = 1; human <= rumor_believe_human; human++){
		cin >> rumor_start;
		rumor_believe[rumor_start] = 0; // 초기부터 루머를 믿게 됨
		neighborhood.push({rumor_start, 0});
	}
	while (!neighborhood.empty()){
		node = neighborhood.front().first; // 지금 루머를 퍼뜨리려는 사람
		minute = neighborhood.front().second; // 루머를 믿게 된 시점
		relations_count = relations_people[node]; // 루머를 퍼뜨리려는 사람의 이웃 수
		neighborhood.pop();
		for (int i = 0; i < relations_count; i++){ // 루머를 퍼뜨리려는 사람의 모든 지인을 검사
			current_neighbor = relations[node][i]; // 루머를 퍼뜨리려는 사람의 지인
			if (rumor_believe[current_neighbor] == -1){ // 지인이 루머를 믿지 않는 사람일 때만 검사
				cout << "node: " << node << ", minute: " << minute << ", relations_count: " << relations_count << ", current_neighbor: " << current_neighbor << '\n';
				count = 0; // 지인의 루머를 믿는 이웃수
				another_neighbor = relations_people[current_neighbor]; // 지인의 이웃 수
				for (int j = 0; j < another_neighbor; j++){ // 지인의 모든 이웃을 검사
					if (rumor_believe[relations[current_neighbor][j]] != -1){ // 지인 주변의 사람이 루머를 믿을 때
						count++;
					}
				}
				int half = (another_neighbor / 2) + (another_neighbor % 2); // 절반의 기준
				cout << "half: " << half << ", count: " << count << '\n';
				if (count >= half){ // 지인의 이웃 수의 절반 이상이 루머를 믿을 때
					gonna_believe_rumor.push(current_neighbor); // 루머를 믿게 된 사람을 큐에 넣음
					cout << current_neighbor << " is gonna believe rumor!\n";
				}
			}
		}
		while (!gonna_believe_rumor.empty()){
			rumor_believe[gonna_believe_rumor.front()] = minute + 1; 
			neighborhood.push({gonna_believe_rumor.front(), minute + 1}); // 지인이 루머를 믿게 됨
			gonna_believe_rumor.pop();
		}
		cout << '\n';
	}
	for (human = 1; human <= human_count; human++){
		cout << rumor_believe[human] << ' ';
	}
}
*/