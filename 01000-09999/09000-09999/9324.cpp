// 9324 진짜 메시지
// https://www.acmicpc.net/problem/9324
#include <iostream>
#include <string>
using namespace std;

int main(){
	int TC, alphabet[26];
	bool flag;
	string s;
	cin >> TC;
	while (TC-- > 0){
		cin >> s;
		flag = true;
		for (int i = 0; i < 26; i++){alphabet[i] = 0;}
		for (int i = 0; i < s.length(); i++){
			alphabet[s[i] - 'A']++;
			if (alphabet[s[i] - 'A'] % 3 == 0){
				if (i == s.length() - 1 || s[i + 1] != s[i]){
					flag = false;
					break;
				}
				i++;
			}
		}
		if (flag){cout << "OK\n";}
		else {cout << "FAKE\n";}
	}
}