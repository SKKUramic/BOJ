// 17244 아맞다우산
// https://www.acmicpc.net/problem/17244
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Item{
	int y;
	int x; 
	int got;
	Item(int a, int b, int c){
		y = a;
		x = b;
		got = c;
	}
};

char map[51][51], c = 'a';
int N, M, zero_y, zero_x;
bool visited[51][51][32], end_flag;
queue<Item> q;

void Search(Item item){
	if (visited[item.y][item.x][item.got] == true){return;} // 이미 방문함
	if (map[item.y][item.x] == '#'){return;} // 벽일 때
	if (map[item.y][item.x] == 'E' && item.got == (1 << (c - 'a')) - 1){ // 도착점에 모든 물건을 들고 왔을 때 종료
		end_flag = true;
		return;
	}
	if ('a' <= map[item.y][item.x] && map[item.y][item.x] <= 'e'){ // 현재 위치에 물건이 있을 때
		int addgot = item.got | (1 << (map[item.y][item.x] - 'a'));
		visited[item.y][item.x][item.got] = true;
		visited[item.y][item.x][addgot] = true;
		q.push(Item(item.y, item.x, addgot));
	}
	else { // '.'이거나 시작점이거나 아직 다 안 가져온 상태로 도착점에 도착했을 때
		visited[item.y][item.x][item.got] = true;
		q.push(Item(item.y, item.x, item.got));
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Item I = Item(0, 0, 0);
	int time = 0, qsize;
	string s;
	cin >> M >> N;
	for (int n = 1; n <= N; n++){
		cin >> s;
		for (int m = 1; m <= M; m++){
			map[n][m] = s[m - 1];
			if (map[n][m] == 'X'){
				map[n][m] = c;
				c++;
			}
			else if (map[n][m] == 'S'){
				zero_y = n;
				zero_x = m;
			}
		}
	}
	q.push(Item(zero_y, zero_x, 0));
	visited[zero_y][zero_x][0] = true;
	while (!q.empty() && end_flag == false){
		time++;
		qsize = q.size();
		while (qsize-- > 0 && end_flag == false){
			I = q.front();
			q.pop();
			if (I.y > 1){Search(Item(I.y - 1, I.x, I.got));}
			if (I.y < N){Search(Item(I.y + 1, I.x, I.got));}
			if (I.x > 1){Search(Item(I.y, I.x - 1, I.got));}
			if (I.x < M){Search(Item(I.y, I.x + 1, I.got));}
		}
	}
	if (end_flag == false){cout << "-1";}
	else {cout << time;}
}