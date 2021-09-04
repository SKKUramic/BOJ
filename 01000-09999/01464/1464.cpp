// 1464 뒤집기 3
// https://www.acmicpc.net/problem/1464
// 뒤집어라 엎어라
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s, answer;
	cin >> s;
	answer = s.substr(0, 1);
	for (int i = 1; i < s.length(); i++){ // 일단 최악의 경우를 만든 후, 그걸 뒤집으면 최선의 경우가 된다
		if (answer[i - 1] < s[i]){ // 답이 될 배열의 맨 마지막 문자보다 s[i]가 사전순으로 뒤일 때
			answer = s[i] + answer;
		}
		else {
			answer = answer + s[i];
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
}