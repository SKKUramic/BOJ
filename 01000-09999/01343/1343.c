// 1343 폴리오미노
// https://www.acmicpc.net/problem/1343
#include <stdio.h>
#include <string.h>

char board[510];

int main(){
	int len, idx = 0, flag = 1;
	scanf("%s", board);
	len = strlen(board);
	while (idx < len){
		if (board[idx] == '.'){idx++;}
		else if (board[idx] == 'X' && board[idx + 1] == 'X'){
			if (board[idx + 2] == 'X' && board[idx + 3] == 'X'){
				board[idx] = 'A';
				board[idx + 1] = 'A';
				board[idx + 2] = 'A';
				board[idx + 3] = 'A';
				idx += 4;
			}
			else if (board[idx + 2] == 'X' && board[idx + 3] != 'X'){
				flag = 0;
				break;
			}
			else if (board[idx + 2] != 'X'){
				board[idx] = 'B';
				board[idx + 1] = 'B';
				idx += 2;
			}
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 0){printf("-1");}
	else {printf("%s", board);}
}