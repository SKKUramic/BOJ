// 9093 단어 뒤집기
// https://www.acmicpc.net/problem/9093
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int TC;
	cin >> TC;
	getline(cin, s);
	while (TC-- > 0){
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			if (s[i] == ' '){
				for (int j = i - 1; j >= 0; j--){
					if (s[j] == ' '){break;}
					cout << s[j];
				}
				cout << s[i];
			}
			else if (i == s.length() - 1){
				for (int j = i; j >= 0; j--){
					if (s[j] == ' '){break;}
					cout << s[j];
				}
			}
		}
		cout << '\n';
	}
}