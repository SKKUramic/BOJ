// 9375 패션왕 신해빈
// https://www.acmicpc.net/problem/9375
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void fashion_king(int N){
	map<string, int> fashion;
	vector<string> all_kinds;
	int answer = 1;
	string name, kind;
	int count = 0;
	for (int j = 0; j < N; j++){
		cin >> name >> kind;
		if (fashion[kind] == 0){
			fashion[kind]++;
			all_kinds.push_back(kind);
			count++;
		}
		else {
			fashion[kind]++;
		}
	}
	if (N == 0){cout << 0 << '\n';}
	else {
		for (int k = 0; k < count; k++){
			answer *= (1 + fashion[all_kinds[k]]);
		}
		answer--;
		cout << answer << '\n';
	}
	return;
}

int main(){
	int T, N, count;
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N;
		fashion_king(N);
	}
}