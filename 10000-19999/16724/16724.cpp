// 16724 피리 부는 사나이
// https://www.acmicpc.net/problem/16724
#include <iostream>
using namespace std;

int N, M, safe_zone = 0, address = 1;
char maze[1001][1001];
int visit[1001][1001];

void DFS(int y, int x){
	if (visit[y][x] == address){return;} // 조사 중 이미 이번 조사에 방문한 곳에 도달했을 경우
	visit[y][x] = address;
	if (maze[y][x] == 'U'){
		maze[y][x] = '#';
		DFS(y - 1, x);
	}
	else if (maze[y][x] == 'R'){
		maze[y][x] = '#';
		DFS(y, x + 1);
	}
	else if (maze[y][x] == 'D'){
		maze[y][x] = '#';
		DFS(y + 1, x);
	}
	else if (maze[y][x] == 'L'){
		maze[y][x] = '#';
		DFS(y, x - 1);
	}
	else if (maze[y][x] == '#'){
		safe_zone--;
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> N >> M;
	for (int n = 1; n <= N; n++){
		cin >> s;
		for (int m = 1; m <= M; m++){
			maze[n][m] = s[m - 1];
		}
	}
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			if (visit[n][m] == false){
				DFS(n, m);
				safe_zone++;
				address++;
			}
		}
	}
	cout << safe_zone;
}