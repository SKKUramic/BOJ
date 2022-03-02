// 4806 줄 세기
// https://www.acmicpc.net/problem/4806
#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int line = 0;
	string s;
	while (1){
		getline(cin, s);
		if (cin.eof()){break;}
		line++;
	}
	cout << line;
}