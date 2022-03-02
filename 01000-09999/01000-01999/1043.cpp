// 1043 거짓말
// https://www.acmicpc.net/problem/1043
// 분리 집합을 배우기 위한 좋은 문제, https://donggoolosori.github.io/2020/11/04/boj-1043/(슥지니 님의 블로그)에서 많이 배웠습니다.
#include <iostream>
#include <vector>
using namespace std;

int parent[51];
vector<int> Know_Truth;
vector<vector<int>> festival(50); // 미리미리 크게 선언함

int FIND(int x){
    if (parent[x] == x){
		return x;
	}
    return FIND(parent[x]);
}

void Union(int x, int y){
	x = FIND(x);
	y = FIND(y);
	parent[x] = y;
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int people, party, truth, truth_people;
	int party_people, participants, prev;
	cin >> people >> party;
	cin >> truth;
	for (int i = 1; i <= 50; i++){
		parent[i] = i;
	}
	for (int t = 0; t < truth; t++){
		cin >> truth_people;
		Know_Truth.push_back(truth_people);
	}
	for (int p = 0; p < party; p++){
		cin >> participants;
		for (int part = 0; part < participants; part++){
			if (part == 0){ // 처음 넣은 사람을 부모로 함
				cin >> party_people;
			}
			else {
				prev = party_people;
				cin >> party_people;
				Union(party_people, prev); // party_people의 부모를 prev로 함
			}
			festival[p].push_back(party_people);
		}
	}
	int answer = party;
	for (int p = 0; p < party; p++){
		bool flag = false;
		for (int person = 0; person < festival[p].size(); person++){
			if (flag == true){break;} // 파티 내에 진실을 아는 사람이 존재한다면
			for (int knowing = 0; knowing < Know_Truth.size(); knowing++){
				if (FIND(festival[p][person]) == FIND(Know_Truth[knowing])){ // 파티 참가자가 진실을 아는 사람과 접촉했거나 할 예정이라면
					flag = true;
					break;
				}
			}
		}
		if (flag == true){answer--;} // 이 파티는 참가하면 큰일난다
	}
	cout << answer;
}