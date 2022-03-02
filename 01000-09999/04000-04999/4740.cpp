// 4740 거울, 오 거울!
// https://www.acmicpc.net/problem/4740
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	while (s.compare("***") != 0){
		reverse(s.begin(), s.end());
		cout << s << '\n';
		getline(cin, s);
	}
}