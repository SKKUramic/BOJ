// 6550 부분 문자열
// https://www.acmicpc.net/problem/6550
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	int idx;
	
	while (1){
		cin >> s >> t;
		if (cin.eof()){break;}
		idx = 0;
		for (int i = 0; i < t.length(); i++){
			if (s[idx] == t[i]){idx++;}
		}
		if (idx == s.length()){cout << "Yes\n";}
		else {cout << "No\n";}
	}
}