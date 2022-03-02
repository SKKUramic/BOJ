// 9046 복호화
// https://www.acmicpc.net/problem/9046
#include <iostream>
#include <string>
using namespace std;

int alphabet[27] = {0, };

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag = true;
	char answer;
	int TC, max_value = -1, max_idx = -1;
	string s;
	cin >> TC;
	getline(cin, s);
	while (TC-- > 0){
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			if (s[i] != ' '){
				alphabet[s[i] - 'a']++;
			}
		}
		for (int i = 0; i < 26; i++){
			if (max_value < alphabet[i]){
				max_value = alphabet[i];
				max_idx = i;
			}
		}
		for (int i = 0; i < 26; i++){
			if (max_value == alphabet[i]){
				if (i != max_idx){
					flag = false;
					break;
				}
			}
		}
		if (flag){
			answer = 'a' + max_idx;
			cout << answer << '\n';
		}
		else {
			cout << "?\n";
		}
		
		flag = true;
		max_value = -1; max_idx = -1;
		for (int i = 0; i < 26; i++){alphabet[i] = 0;}
	}
}