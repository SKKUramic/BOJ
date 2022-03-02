// 11899 괄호 끼워넣기
// https://www.acmicpc.net/problem/11899
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;

int main(){
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		if (!s.empty() && str[i] == ')' && s.top() == '('){
			s.pop();
		}
		else {
			s.push(str[i]);
		}
	}
	cout << s.size();
}