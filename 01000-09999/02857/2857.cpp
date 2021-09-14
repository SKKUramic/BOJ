// 2857 FBI
// https://www.acmicpc.net/problem/2857
#include <iostream>
#include <string>
using namespace std;

int main(){
	int len, count = 0;
	string s;
	for (int k = 0; k < 5; k++){
		cin >> s;
		len = s.length();
		for (int i = 0; i < len - 2; i++){
			if (s[i] == 'F' && s[i + 1] == 'B' && s[i + 2] == 'I'){
				cout << k + 1<< ' ';
				count++;
				break;
			}
		}
	}
	if (count == 0) {cout << "HE GOT AWAY!";}
}