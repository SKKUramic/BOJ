// 1371 가장 많은 글자
// https://www.acmicpc.net/problem/1371
#include <iostream>
#include <string>
using namespace std;

int alphabet[26] = {0, };
int MAX = -1;

int main(){
	char c;
	string s;
	while(!cin.eof()){
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			if (s[i] >= 'a' && s[i] <= 'z'){
				alphabet[s[i] - 'a']++;
			}
		}
	}
	for (int i = 0; i < 26; i++){
		if (alphabet[i] > MAX){
			MAX = alphabet[i];
		}
	}
	for (int i = 0; i < 26; i++){
		if (alphabet[i] == MAX){
			c = 'a' + i;
			cout << c;
		}
	}
}