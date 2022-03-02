// 2744 대소문자 바꾸기
// https://www.acmicpc.net/problem/2744
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[101];
	cin >> s;
	for (int i = 0; i < strlen(s); i++){
		if ('A' <= s[i] && s[i] <= 'Z'){
			s[i] = s[i] - 'A' + 'a';
		}
		else {
			s[i] = s[i] - 'a' + 'A';
		}
		cout << s[i];
	}
}