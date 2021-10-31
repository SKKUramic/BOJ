// 10820 문자열 분석
// https://www.acmicpc.net/problem/10820
#include <iostream>
#include <string>
using namespace std;

int main(){
	int count[4] = {0, };
	string s;
	while (1){
		getline(cin, s);
		if (cin.eof()){break;}
		for (int i = 0; i < s.length(); i++){
			if ('a' <= s[i] && s[i] <= 'z'){count[0]++;}
			else if ('A' <= s[i] && s[i] <= 'Z'){count[1]++;}
			else if ('0' <= s[i] && s[i] <= '9'){count[2]++;}
			else if (s[i] == ' '){count[3]++;}
			
		}
		for (int i = 0; i < 4; i++){
			cout << count[i] << ' ';
			count[i] = 0;
		}
		cout << '\n';
	}
}