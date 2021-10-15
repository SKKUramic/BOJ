// 5218 알파벳 거리
// https://www.acmicpc.net/problem/5218
#include <iostream>
#include <string>
using namespace std;

int main(){
	int TC;
	string s, t;
	cin >> TC;
	while (TC-- > 0){
		cin >> s >> t;
		cout << "Distances: ";
		for (int i = 0; i < s.length(); i++){
			if (s[i] <= t[i]){
				cout << (int)(t[i] - s[i]) << ' ';
			}
			else {
				cout << (int)(t[i] + 26 - s[i]) << ' ';
			}
		}
		cout << '\n';
	}
}