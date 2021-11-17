// 16234 인구 이동
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 123456789
using namespace std;

typedef pair<int, int> pii;

bool visited[51][51], Wvisited[51][51], goal = false;
int water[51][51] = {0, };
char map[51][51];
int R, C, MinTime = MAX;
pii D, S, W;

void water_bfs(){
	if (W.first == -1 && W.second == -1){return;}
	queue<pii> q;
	int qsize, r, c, water_time = 0;
	q.push(W);
	Wvisited[W.first][W.second] = true;
	while (!q.empty()){
		qsize = q.size();
		for (int i = 0; i < qsize; i++){
			r = q.front().first; c = q.front().second;
			q.pop();
			if (map[r][c] == 'X' || map[r][c] == 'D'){
				water[r][c] = MAX;
				continue;
			}
			Wvisited[r][c] = true;
			if (water_time < water[r][c]){water[r][c] = water_time;}
			if (r > 0 && Wvisited[r - 1][c] == false){
				Wvisited[r - 1][c] = true;
				q.push({r - 1, c});
			}
			if (c > 0 && Wvisited[r][c - 1] == false){
				Wvisited[r][c - 1] = true;
				q.push({r, c - 1});
			}
			if (r < R - 1 && Wvisited[r + 1][c] == false){
				Wvisited[r + 1][c] = true;
				q.push({r + 1, c});
			}
			if (c < C - 1 && Wvisited[r][c + 1] == false){
				Wvisited[r][c + 1] = true;
				q.push({r, c + 1});
			}
		}
		//cout << "WATER\n";
		water_time++;
	}
	return;
}

void sonic_bfs(){
	queue<pii> q;
	int qsize, r, c, sonic_time = 0;
	q.push(S);
	visited[S.first][S.second] = true;
	while (!q.empty()){
		qsize = q.size();
		for (int i = 0; i < qsize; i++){
			r = q.front().first; c = q.front().second;
			q.pop();
			if (map[r][c] == 'X' || water[r][c] <= sonic_time){continue;}
			if (map[r][c] == 'D'){
				MinTime = sonic_time;
				return;
			}
			if (r > 0 && visited[r - 1][c] == false){
				visited[r - 1][c] = true;
				q.push({r - 1, c});
			}
			if (c > 0 && visited[r][c - 1] == false){
				visited[r][c - 1] = true;
				q.push({r, c - 1});
			}
			if (r < R - 1 && visited[r + 1][c] == false){
				visited[r + 1][c] = true;
				q.push({r + 1, c});
			}
			if (c < C - 1 && visited[r][c + 1] == false){
				visited[r][c + 1] = true;
				q.push({r, c + 1});
			}
		}
		//cout << "SONIC\n";
		sonic_time++;
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	W.first = -1; W.second = -1;
	for (int r = 0; r < R; r++){
		cin >> map[r];
		for (int c = 0; c < C; c++){
			water[r][c] = MAX;
			if (map[r][c] == 'S'){S.first = r; S.second = c;}
			if (map[r][c] == 'D'){D.first = r; D.second = c;}
		}
	}
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			if (map[r][c] == '*'){
				W.first = r; W.second = c;
				memset(Wvisited, false, sizeof(Wvisited));
				water_bfs();
			}
		}
	}
	sonic_bfs();
	if (MinTime == MAX){cout << "KAKTUS";}
	else {cout << MinTime;}
}