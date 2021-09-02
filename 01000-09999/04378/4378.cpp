// 4378 트ㅏㅊ;
// https://www.acmicpc.net/problem/4378
#include <iostream>
#include <string>
using namespace std;

string list = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int list_len;

char translate(char c){
	if (c == ' ') {return c;}
	else {
		for (int i = 0; i < list_len; i++){
			if (list[i] == c){
				return list[i - 1];
			}
		}
	}
	return '?';
}

int main(){
	string s;
	list_len = list.length();
	while (cin.eof() == false){
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			cout << translate(s[i]);
		}
		if (s.length() != 0) {cout << '\n';}
	}
}