// 8941 Molar mass
// https://www.acmicpc.net/problem/8941
#include <iostream>
#include <string>
using namespace std;

double mol[4] = {12.010, 1.008, 16.000, 14.010};

int retIDX(char c){
	if (c == 'C'){return 0;}
	else if (c == 'H'){return 1;}
	else if (c == 'O'){return 2;}
	else if (c == 'N'){return 3;}
	else {return -1;}
}

int main(){
	int TC, len;
	char Atom;
	double answer;
	string s;
	cin >> TC;
	while (TC-- > 0){
		cin >> s;
		len = s.length();
		answer = 0.0;
		Atom = 'X';
		for (int idx = 0; idx < len; idx++){
			if ('0' <= s[idx] && s[idx] <= '9'){
				int cnt = 0;
				while (idx < len){
					if (s[idx] < '0' || s[idx] > '9'){idx--; break;}
					cnt = cnt * 10 + (s[idx] - '0');
					idx++;
				}
				answer += mol[retIDX(Atom)] * cnt;
				Atom = 'X';
			}
			else {
				if (Atom == 'X'){
					Atom = s[idx];
				}
				else {
					answer += mol[retIDX(Atom)];
					Atom = s[idx];
				}
			}
		}
		if (Atom != 'X'){answer += mol[retIDX(Atom)];}
		printf("%.3lf\n", answer);
	}
}