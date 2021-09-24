// 1759 암호 만들기
// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alphabet[16];

bool is_vowel(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){return true;}
	else {return false;}
}

void password(string s, int idx, int vowel, int consonant){ // 지금까지 만든 암호, index, 모음, 자음
	if (s.length() == L){ // 전부 다 채웠을 경우
		if (vowel == 0 || consonant < 2){return;}
		cout << s << '\n';
		return;
	}
	for (int c = idx + 1; c < C; c++){
		if (is_vowel(alphabet[c]) == true){
			password(s + alphabet[c], c, vowel + 1, consonant);
		}
		else {
			password(s + alphabet[c], c, vowel, consonant + 1);
		}
	}
	return;
}

int main(){
	string s = "";
	cin >> L >> C;
	for (int c = 0; c < C; c++){
		cin >> alphabet[c];
	}
	sort(alphabet, alphabet + C);
	for (int c = 0; c < C; c++){
		if (is_vowel(alphabet[c]) == true){
			password(s + alphabet[c], c, 1, 0);
		}
		else {
			password(s + alphabet[c], c, 0, 1);
		}
	}
}