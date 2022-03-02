// 7682 틱택토
// https://www.acmicpc.net/problem/7682
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while (1){
		cin >> s;
		if (s.compare("end") == 0){break;}
		char board[3][3];
		int Ocount = 0, Xcount = 0, nothing = 0;
		int Owin = 0, Xwin = 0;
		for (int i = 0; i < 9; i++){
			if (s[i] == 'O'){Ocount++;}
			else if (s[i] == 'X'){Xcount++;}
			else {nothing++;}
			board[i / 3][i % 3] = s[i];
		}
		for (int i = 0; i < 3; i++){
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
				if (board[i][0] == 'O'){Owin++;}
				else if (board[i][0] == 'X'){Xwin++;}
			}
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
				if (board[0][i] == 'O'){Owin++;}
				else if (board[0][i] == 'X'){Xwin++;}
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
			if (board[0][0] == 'O'){Owin++;}
			else if (board[0][0] == 'X'){Xwin++;}
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
			if (board[2][0] == 'O'){Owin++;}
			else if (board[2][0] == 'X'){Xwin++;}
		}
		if (!(Ocount == Xcount || Xcount == Ocount + 1)){
			cout << "invalid\n";
		}
		else {
			if (Ocount == Xcount && Owin >= 1 && Xwin == 0){
				cout << "valid\n";
			}
			else if (Ocount + 1 == Xcount && Owin == 0 && Xwin >= 1){
				cout << "valid\n";
			}
			else if (Ocount + 1 == Xcount && Ocount + Xcount == 9 && Owin == 0){ // 꽉 채웠음
				cout << "valid\n";
			}
			else {
				cout << "invalid\n";
			}
		}
	}
}