// 11718 그대로 출력하기
// https://www.acmicpc.net/problem/11718
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while(cin.eof() == false){
		getline(cin, s);
		cout << s << '\n';
	}
}