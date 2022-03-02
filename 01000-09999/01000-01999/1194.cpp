// 1194 달이 차오른다, 가자.
// https://www.acmicpc.net/problem/1194
// 9328 열쇠의 다운그레이드 버전...?
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Moon{ 
	int y; 
	int x; 
	int key; // 솔직히 short로 해도 되긴 함
	Moon(int a, int b, int c){ 
		y = a; 
		x = b; 
		key = c; 
	}
};

char map[51][51];
int height, width, zero_y, zero_x;
bool visited[51][51][64]; // 키의 조합 가짓수가 64가지?
bool end_flag = false;
queue<Moon> q;

void Search(Moon moon){
	if (visited[moon.y][moon.x][moon.key] == true){return;}
	if (map[moon.y][moon.x] == '#'){return;}
	if (map[moon.y][moon.x] == '1'){ // 도착점에 왔을 때 종료
		end_flag = true;
		return;
	}
	if ('a' <= map[moon.y][moon.x] && map[moon.y][moon.x] <= 'f'){ // 열쇠를 습득할 수 있을 때
		int addkey = moon.key | (1 << (map[moon.y][moon.x] - 'a'));
		visited[moon.y][moon.x][moon.key] = true;
		visited[moon.y][moon.x][addkey] = true;
		q.push(Moon(moon.y, moon.x, addkey));
	}
	else if ('A' <= map[moon.y][moon.x] && map[moon.y][moon.x] <= 'F'){
		if (moon.key & (1 << (map[moon.y][moon.x] - 'A'))){ // 문에 맞는 열쇠가 존재한다면, 없다면 아무 행동도 할 수 없다
			visited[moon.y][moon.x][moon.key] = true;
			q.push(Moon(moon.y, moon.x, moon.key));
		}
	}
	else { // '.'이거나 시작점일 경우
		visited[moon.y][moon.x][moon.key] = true;
		q.push(Moon(moon.y, moon.x, moon.key));
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Moon m = Moon(0, 0, 0); // 초기화는 해야 한다고 해서ㅎㅎ
	string s;
	int qsize, time = 0;
	cin >> height >> width;
	for (int h = 1; h <= height; h++){
		cin >> s;
		for (int w = 1; w <= width; w++){
			map[h][w] = s[w - 1];
			if (map[h][w] == '0'){
				zero_y = h;
				zero_x = w;
			}
		}
	}
	q.push(Moon(zero_y, zero_x, 0));
	visited[zero_y][zero_x][0] = true;
	while (!q.empty() && end_flag == false){
		time++;
		qsize = q.size();
		while (qsize-- > 0 && end_flag == false){
			m = q.front();
			q.pop();
			if (m.y > 1){Search(Moon(m.y - 1, m.x, m.key));}
			if (m.y < height){Search(Moon(m.y + 1, m.x, m.key));}
			if (m.x > 1){Search(Moon(m.y, m.x - 1, m.key));}
			if (m.x < width){Search(Moon(m.y, m.x + 1, m.key));}
		}
	}
	if (end_flag == false){cout << "-1";}
	else {cout << time;}
}