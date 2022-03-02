// 2998 8진수
// https://www.acmicpc.net/problem/2998
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int answer[100] = {0, };
	int idx = 0, two = 0, pow_two = 1;
	cin >> s;
	int len = s.length();
	for (int i = len - 1; i >= 0; i--){
		if (pow_two == 8){
			answer[idx++] = two;
			pow_two = 1;
			two = 0;
		}
		two += pow_two * (s[i] - '0');
		pow_two *= 2;
	}
	answer[idx++] = two;
	for (int i = idx - 1; i >= 0; i--){
		cout << answer[i];
	}
}