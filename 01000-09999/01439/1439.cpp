// 1439 뒤집기
// https://www.acmicpc.net/problem/1439
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int len, zero_count = 0, one_count = 0, current_num, answer;
	cin >> s;
	len = s.length();
	current_num = s[0] - '0';
	if (current_num == 0) {zero_count++;}
	else {one_count++;}
	for (int i = 1; i < len; i++){
		if (current_num == 0 && s[i] == '1'){
			current_num = 1;
			one_count++;
		}
		else if (current_num == 1 && s[i] == '0'){
			current_num = 0;
			zero_count++;
		}
	}
	answer = zero_count < one_count ? zero_count : one_count;
	cout << answer;
}