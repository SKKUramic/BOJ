// 11656 접미사 배열
// https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> S;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int len;
	string s;
	cin >> s;
	len = s.length();
	for (int i = 0; i < len; i++){
		S.push_back(s.substr(i));
	}
	sort(S.begin(), S.end());
	for (int i = 0; i < S.size(); i++){
		cout << S[i] << '\n';
	}
}