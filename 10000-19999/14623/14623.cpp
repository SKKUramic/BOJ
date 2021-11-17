// 14623 감정이입
// https://www.acmicpc.net/problem/14623
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long ten(string s){
	long long ret = 0;
	for (int i = 0; i < s.length(); i++){
		ret = ret * 2 + (s[i] - '0');
	}
	return ret;
}

int main(){
	string A, B;
	cin >> A;
	cin >> B;
	long long answer = ten(A) * ten(B);
	string print;
	for (int i = 0; answer != 0; i++){
		print += ('0' + answer % 2);
		answer /= 2;
	}
	reverse(print.begin(), print.end());
	cout << print;
}