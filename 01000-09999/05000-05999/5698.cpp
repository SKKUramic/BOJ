// 5698 Tautogram
// https://www.acmicpc.net/problem/5698
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	bool flag;
	char ans;
	string s;
	getline(cin, s);
	while (s[0] != '*'){
		ans = tolower(s[0]);
		flag = true;
		for (int i = 1; i < s.length(); i++){
			if (s[i] == ' ' && tolower(s[i + 1]) != ans){
				flag = false;
			}
		}
		if (flag){cout << "Y\n";}
		else {cout << "N\n";}
		getline(cin, s);
	}
}