// 5637 가장 긴 단어
// https://www.acmicpc.net/problem/5637
#include <iostream>
#include <string>
using namespace std;

int main(){
	int max_len = -1, len, slen;
	string ans, s;
	while (1){
		cin >> s;
		if (cin.eof()){break;}
		slen = s.length(); len = 0;
		for (int i = 0; i < s.length(); i++){
			if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') || s[i] == '-'){len++;}
			else {
				if (len > max_len){
					ans = s.substr(i - len, i);
					max_len = len;
				}
				len = 0;
			}
		}
		if (len > max_len && s.compare("E-N-D") != 0){
			ans = s.substr(slen - len, slen);
			max_len = len;
		}
	}
	for (int i = 0; i < ans.length(); i++){
		if (ans[i] >= 'A' && ans[i] <= 'Z'){
			ans[i] += 32;
		}
		if (('A' <= ans[i] && ans[i] <= 'Z') || ('a' <= ans[i] && ans[i] <= 'z') || ans[i] == '-'){
			cout << ans[i];
		}
		else {break;}
	}
}