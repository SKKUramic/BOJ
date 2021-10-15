// 10988 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988
#include <iostream>
#include <string>
using namespace std;

int main(){
	int flag = 1;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (s[i] != s[s.length() - i - 1]){
			flag = 0;
			break;
		}
	}
	cout << flag;
}