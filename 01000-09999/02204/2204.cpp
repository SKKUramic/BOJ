// 2204 도비의 난독증 테스트
// https://www.acmicpc.net/problem/2204
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

bool cmp(pair<string, string> a, pair<string, string> b){
	return a.first < b.first;
}

int main(){
	vector<pair<string, string>> P;
	string s, t;
	int N;
	cin >> N;
	while (N != 0){
		for (int i = 0; i < N; i++){
			cin >> s;
			t.resize(s.length());
			for (int i = 0; i < s.length(); i++){
				t[i] = tolower(s[i]);
			}
			P.push_back({t, s});
		}
		sort(P.begin(), P.end(), cmp);
		cout << P[0].second << '\n';
		P.clear();
		cin >> N;
	}
}