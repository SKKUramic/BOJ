// 9328 열쇠
// https://www.acmicpc.net/problem/9328
#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

char map[102][102];
pair<int, int> door[26];
int T, height, width, document;
int key_list, qsize;
string s;
queue<pair<int, int>> q, locked_door;

void Search(int y, int x){
	if (map[y][x] == '#' || map[y][x] == '*'){ // 이미 지나온 영역이거나 벽일 경우
		return;
	}
	else if ('A' <= map[y][x] && map[y][x] <= 'Z'){ // 잠긴 문일 때
		locked_door.push({y, x});
		return;
	}
	else if ('a' <= map[y][x] && map[y][x] <= 'z'){ // 열쇠일 때
		key_list |= (1 << (map[y][x] - 'a'));
	}
	else if (map[y][x] == '$'){ // 문서가 있을 때
		document++;
	}
	map[y][x] = '#';
	q.push({y, x});
	return;
}

int main(){
	char c;
	pair<int, int> p;
	cin >> T;
	while (T-- > 0){
		key_list = 0; document = 0;
		cin >> height >> width;
		for (int h = 0; h <= height + 1; h++){
			if (h == 0 || h == (height + 1)){
				for (int w = 0; w <= width + 1; w++){
					map[h][w] = '.';
				}
			}
			else {
				cin >> s;
				for (int w = 0; w <= width + 1; w++){
					if (w == 0 || w == (width + 1)){map[h][w] = '.';}
					else {map[h][w] = s[w - 1];}
				}
			}
		}
		cin >> s;
		if (s[0] != '0'){
			for (int k = 0; k < s.length(); k++){
				key_list |= (1 << (s[k] - 'a'));
			}
		}
		map[0][0] = '#';
		// 초기화
		while (!q.empty()) {q.pop();}
		while (!locked_door.empty()) {locked_door.pop();}
		q.push({0, 0});
		// BFS 시작
		while (!q.empty()){
			qsize = q.size();
			while (qsize-- > 0){
				p = q.front();
				q.pop();
				// 가고자 하는 영역이 존재하는 영역일 때 그 영역을 검사함
				if (p.first > 0){Search(p.first - 1, p.second);}
				if (p.first <= height){Search(p.first + 1, p.second);}
				if (p.second > 0){Search(p.first, p.second - 1);}
				if (p.second <= width){Search(p.first, p.second + 1);}
			}
			qsize = locked_door.size();
			while (qsize-- > 0){ // 잠긴 문에 대해 검사함
				p = locked_door.front();
				locked_door.pop();
				if (key_list & (1 << (map[p.first][p.second] - 'A'))){ // 이 좌표에 있는 문과 맞는 열쇠가 있다면
					map[p.first][p.second] = '#'; // 해당 영역을 지난 것으로 간주함
					q.push(p);
				}
				else {
					locked_door.push(p);
				}
			}
		}
		cout << document << '\n';
	}
}