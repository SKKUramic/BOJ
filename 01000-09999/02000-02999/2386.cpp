// 2386 도비의 영어 공부
// https://www.acmicpc.net/problem/2386
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	char x;
	int count;
	cin >> x;
	while (x != '#'){
		count = 0;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++){
			if (x == tolower(s[i])){count++;}
		}
		cout << x << ' ' << count << '\n';
		cin >> x;
	}
}