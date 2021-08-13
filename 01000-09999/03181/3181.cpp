// 3181 줄임말 만들기
// https://www.acmicpc.net/problem/3181
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool isVALID(string s){
	string invalid[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
	for (int i = 0; i < 10; i++){
		if (s.compare(invalid[i]) == 0){return false;}
	}
	return true;
}

int main(){
	int idx = 0;
	string s;
	char c;
	while (!cin.eof()){
		cin >> s;
		if (cin.eof()){break;}
		if (idx == 0 || isVALID(s) == true){
			c = toupper(s[0]);
			cout << c;
		}
		idx++;
	}
}