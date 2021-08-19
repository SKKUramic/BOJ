// 4659 비밀번호 발음하기
// https://www.acmicpc.net/problem/4659
#include <iostream>
#include <string>
using namespace std;

int vowel[5];

bool is_vowel(char c){
	if (c == 'a'){return true;}
	else if (c == 'e') {return true;}
	else if (c == 'i') {return true;}
	else if (c == 'o') {return true;}
	else if (c == 'u') {return true;}
	else {return false;}
}

void find_vowel(char c){
	if (c == 'a'){vowel[0]++;}
	else if (c == 'e') {vowel[1]++;}
	else if (c == 'i') {vowel[2]++;}
	else if (c == 'o') {vowel[3]++;}
	else if (c == 'u') {vowel[4]++;}
	return;
}

int main(){
	int len;
	bool flag;
	string s;
	while (1){
		cin >> s;
		if (s.compare("end") == 0){
			break;
		}
		flag = true;
		for (int i = 0; i < 5; i++) {vowel[i] = 0;}
		len = s.length();
		for (int i = 0; i < len; i++){
			if (i < len - 2){
				if (is_vowel(s[i]) == is_vowel(s[i + 1]) && is_vowel(s[i + 1]) == is_vowel(s[i + 2])){
					flag = false;
				}
			}
			if (i < len - 1){
				if (s[i] == s[i + 1] && (s[i] != 'e' && s[i] != 'o')){
					flag = false;
				}
			}
			find_vowel(s[i]);
		}
		for (int i = 0; i < 5; i++) {
			if (vowel[i] != 0){break;}
			if (i == 4){flag = false;}
		}
		if (flag == true){
			cout << '<' << s << "> is acceptable.\n";
		}
		else {
			cout << '<' << s << "> is not acceptable.\n";
		}
	}
}