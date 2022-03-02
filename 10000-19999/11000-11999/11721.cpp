// 11721 열 개씩 끊어 출력하기
// https://www.acmicpc.net/problem/11721
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		cout << s[i];
		if (i % 10 == 9){cout << '\n';}
	}
}