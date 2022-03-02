// 12904 A와 B
// https://www.acmicpc.net/problem/12904
// EZ
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	char last;
	string original, s;
	cin >> original;
	cin >> s;
	while(s.length() > original.length()){
		last = s.back();
		s.pop_back();
		if (last == 'B'){
			reverse(s.begin(), s.end());
		}
	}
	if (s.compare(original) == 0){
		cout << 1;
	}
	else {
		cout << 0;
	}
}