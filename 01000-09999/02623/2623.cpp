// 2623 음악프로그램
// https://www.acmicpc.net/problem/2623
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int InDegree[1001] = {0, };
int result[1001] = {0, };
vector<int> topology[1001];
bool not_solo[1001] = {false, };
bool linked[1001][1001] = {false, };
bool ERROR = false;

void topology_sort(int N){
	queue<int> q;
	for (int i = 1; i <= N; i++){
		if (InDegree[i] == 0){q.push(i);}
	}
	for (int i = 1; i <= N; i++){
		if (q.empty()){
			ERROR = true;
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < topology[x].size(); i++){
			int y = topology[x][i];
			if (--InDegree[y] == 0){
				q.push(y);
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int singer, PD, num, PD_singer;
	cin >> singer >> PD;
	for (int p = 0; p < PD; p++){
		vector<int> v;
		cin >> PD_singer;
		for (int k = 0; k < PD_singer; k++){
			cin >> num;
			v.push_back(num);
		}
		for (int idx = 0; idx < v.size() - 1; idx++){ // 위상 정렬하기 편하게 형태를 바꿈
			if (linked[v[idx]][v[idx + 1]] == false){ // 중복 방지
				topology[v[idx]].push_back(v[idx + 1]);
				InDegree[v[idx + 1]]++;
				linked[v[idx]][v[idx + 1]] = true;
			}
		}
	}
	topology_sort(singer);
	if (ERROR == true){ // 사이클이 존재할 경우
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= singer; i++){
		not_solo[result[i]] = true;
		cout << result[i] << '\n';
	}
	for (int i = 1; i <= singer; i++){ // 위상 정렬에 포함이 되지 않은 가수는 맨 뒤에 둠
		if (not_solo[i] == false){
			cout << i << '\n';
		}
	}
}