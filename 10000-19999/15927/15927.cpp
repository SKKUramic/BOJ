// 15927 회문은 회문아니야!!
// https://www.acmicpc.net/problem/15927
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int start, end, len, answer = -1;
	bool all_same = true, is_palindrome = true;
	string s;
	cin >> s;
	len = s.length();
	start = 0; end = len - 1;
	for (int i = 0; i < len; i++){
		if (s[i] != s[0]){all_same = false;}
		if (s[i] != s[len - i - 1]){is_palindrome = false;}
	}
	if (all_same == true){ // 모든 알파벳이 같음
		cout << "-1";
		return 0;
	}
	if (is_palindrome == true){ // 회문임
		cout << len - 1;
	}
	else { // 회문 아님
		cout << len;
	}
	return 0;
}