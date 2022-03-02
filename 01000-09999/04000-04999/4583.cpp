// 4583 거울상
// https://www.acmicpc.net/problem/4583
#include <iostream>
#include <string>
using namespace std;

bool isValid(string s){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == 'b' || s[i] == 'd' || s[i] == 'p' || s[i] == 'q' || s[i] == 'i' || s[i] == 'o' || s[i] =='v' || s[i] == 'w' || s[i] == 'x'){
			continue;
		}
		else {return false;}
	}
	return true;
}

string mirror(string s){
	string ret = "";
	for (int i = s.length() - 1; i >= 0; i--){
		if (s[i] == 'b'){ret += 'd';}
		else if (s[i] == 'd'){ret += 'b';}
		else if (s[i] == 'p'){ret += 'q';}
		else if (s[i] == 'q'){ret += 'p';}
		else {ret += s[i];}
	}
	return ret;
}

int main(){
	string s, answer;
	while (1){
		cin >> s;
		if (s.length() == 1 && s[0] == '#'){break;}
		if (isValid(s) == true){
			answer = mirror(s);
			cout << answer << '\n';
		}
		else {
			 cout << "INVALID\n";
		}
	}
}