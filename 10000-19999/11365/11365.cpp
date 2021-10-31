// 11365 !밀비 급일
// https://www.acmicpc.net/problem/11365
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	while (1){
		getline(cin, s);
		if (s.compare("END") == 0){break;}
		for (int i = s.length() - 1; i >= 0; i--){
			cout << s[i];
		}
		cout << '\n';
	}
}