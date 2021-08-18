// 4458 첫 글자를 대문자로
// https://www.acmicpc.net/problem/4458
#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int N;
	cin >> N;
	getline(cin, s);
	for (int i = 0; i < N; i++){
		getline(cin, s);
		if (s[0] >= 97){s[0] -= 32;}
		cout << s << '\n';
	}
}