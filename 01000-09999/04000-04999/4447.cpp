// 4447 좋은놈 나쁜놈
// https://www.acmicpc.net/problem/4447
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int N, g, b;
	cin >> N;
	getline(cin, s);
	while (N-- > 0){
		g = 0; b = 0;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			if (s[i] == 'g' || s[i] == 'G'){g++;}
			else if (s[i] == 'b' || s[i] == 'B'){b++;}
		}
		if (g > b){
			cout << s << " is GOOD\n";
		}
		else if (g < b){
			cout << s << " is A BADDY\n";
		}
		else {
			cout << s << " is NEUTRAL\n";
		}
	}
}