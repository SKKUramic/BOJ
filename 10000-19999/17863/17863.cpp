// 17863 FYI
// https://www.acmicpc.net/problem/17863
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	if (s[0] == '5' && s[1] == '5' && s[2] == '5'){
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}