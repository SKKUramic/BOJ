// 1987 알파벳
// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <string>
using namespace std;

int R, C, max_count = 0;
char board[21][21];
bool visited[26] = {false, };

void DFS(int y, int x, int count){
	if (count > max_count){max_count = count;}
	if (y > 0 && visited[board[y - 1][x] - 'A'] == false){
		visited[board[y - 1][x] - 'A'] = true;
		DFS(y - 1, x, count + 1);
		visited[board[y - 1][x] - 'A'] = false;
	}
	if (y < R - 1 && visited[board[y + 1][x] - 'A'] == false){
		visited[board[y + 1][x] - 'A'] = true;
		DFS(y + 1, x, count + 1);
		visited[board[y + 1][x] - 'A'] = false;
	}
	if (x > 0 && visited[board[y][x - 1] - 'A'] == false){
		visited[board[y][x - 1] - 'A'] = true;
		DFS(y, x - 1, count + 1);
		visited[board[y][x - 1] - 'A'] = false;
	}
	if (x < C - 1 && visited[board[y][x + 1] - 'A'] == false){
		visited[board[y][x + 1] - 'A'] = true;
		DFS(y, x + 1, count + 1);
		visited[board[y][x + 1] - 'A'] = false;
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> R >> C;
	for (int r = 0; r < R; r++){
		cin >> s;
		for (int c = 0; c < C; c++){
			board[r][c] = s[c];
		}
	}
	visited[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	visited[board[0][0] - 'A'] = false;
	cout << max_count;
}