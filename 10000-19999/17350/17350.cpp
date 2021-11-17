// 17350 2루수 이름이 뭐야
// https://www.acmicpc.net/problem/17350
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag = false;
	int N, len;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		len = s.length();
		if (s.length() == 3 && s[0] == 'a' && s[1] == 'n' && s[2] == 'j'){flag = true;}
	}
	if (flag){cout << "뭐야;";}
	else {cout << "뭐야?";}
}