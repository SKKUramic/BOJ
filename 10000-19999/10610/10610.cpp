// 10610 30
// https://www.acmicpc.net/problem/10610
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int idx = -1, zero_count = 0, is_three = 0;
	string s, t;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '0'){
			zero_count++;
		}
		else {
			t += s[i];
			is_three += s[i] - '0';
		}
	}
	if (zero_count == 0 || is_three % 3 != 0){cout << "-1"; return 0;}
	sort(t.begin(), t.end(), greater<>());
	for (int i = 0; i < t.length(); i++){
		cout << t[i];
	}
	while (zero_count-- > 0){
		cout << '0';
	}
}