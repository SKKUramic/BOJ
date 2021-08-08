// 1388 바닥 장식
// https://www.acmicpc.net/problem/1388
#include <iostream>
using namespace std;

int N, M, count = 0;
char pattern[101][101];
bool Floor[101][101];
char cur_pattern;

void DFS(int y, int x){
	if (cur_pattern != pattern[y][x]) {
		count++;
		return;
	}
	Floor[y][x] = true;
	if (cur_pattern == '-') {
		if (x < M - 1){
			DFS(y, x + 1);
		}
		else {
			count++;
			return;
		}
	}
	else if (cur_pattern == '|'){
		if (y < N - 1){
			DFS(y + 1, x);
		}
		else {
			count++;
			return;
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> pattern[i];
	}
	cur_pattern = pattern[0][0];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (Floor[i][j] != true){	
				cur_pattern = pattern[i][j];
				DFS(i, j);
			}
		}
	}
	cout << count;
}