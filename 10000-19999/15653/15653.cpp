// 15653 구슬 탈출 4
// https://www.acmicpc.net/problem/15653
// 13460 구슬 탈출 2 문제에서 시간 제한을 없앤 문제로, 코드 또한 시간 제한을 없앤 것을 제외하면 동일합니다
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct Marble{
	int red_marble_y;
	int red_marble_x;
	int blue_marble_y;
	int blue_marble_x;
	Marble(int ry, int rx, int by, int bx){
		red_marble_y = ry;
		red_marble_x = rx;
		blue_marble_y = by;
		blue_marble_x = bx;
	}
	bool operator !=(Marble marble) {
		if (red_marble_y != marble.red_marble_y) {return true;}
		if (red_marble_x != marble.red_marble_x) {return true;}
		if (blue_marble_y != marble.blue_marble_y) {return true;}
		if (blue_marble_x != marble.blue_marble_x) {return true;}
		return false;
    }
};

int N, M, qsize, move_count = 0;
char marble_map[11][11];
bool visit[11][11][11][11] = {false, };
queue<Marble> q;
bool can_exit = false;

void MOVE(Marble marble, char direction){ // 효율적으로 못 짰음ㅎㅎ;;
	Marble temp = marble;
	bool red_exit = false, blue_exit = false;
	if (direction == 'L'){
		if (marble.red_marble_x < marble.blue_marble_x){
			while (1){
				if (marble_map[marble.red_marble_y][marble.red_marble_x - 1] == '#'){break;}
				else if (marble.red_marble_y == marble.blue_marble_y && marble.red_marble_x - 1 == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y][marble.red_marble_x - 1] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_x--;
			}
			while (1){
				if (marble_map[marble.blue_marble_y][marble.blue_marble_x - 1] == '#'){break;}
				else if (marble.blue_marble_y == marble.red_marble_y && marble.blue_marble_x - 1 == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y][marble.blue_marble_x - 1] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_x--;
			}
		}
		else {
			while (1){
				if (marble_map[marble.blue_marble_y][marble.blue_marble_x - 1] == '#'){break;}
				else if (marble.blue_marble_y == marble.red_marble_y && marble.blue_marble_x - 1 == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y][marble.blue_marble_x - 1] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_x--;
			}
			while (1){
				if (marble_map[marble.red_marble_y][marble.red_marble_x - 1] == '#'){break;}
				else if (marble.red_marble_y == marble.blue_marble_y && marble.red_marble_x - 1 == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y][marble.red_marble_x - 1] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_x--;
			}
		}
	}
	else if (direction == 'R'){
		if (marble.red_marble_x > marble.blue_marble_x){
			while (1){
				if (marble_map[marble.red_marble_y][marble.red_marble_x + 1] == '#'){break;}
				else if (marble.red_marble_y == marble.blue_marble_y && marble.red_marble_x + 1 == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y][marble.red_marble_x + 1] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_x++;
			}
			while (1){
				if (marble_map[marble.blue_marble_y][marble.blue_marble_x + 1] == '#'){break;}
				else if (marble.blue_marble_y == marble.red_marble_y && marble.blue_marble_x + 1 == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y][marble.blue_marble_x + 1] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_x++;
			}
		}
		else {
			while (1){
				if (marble_map[marble.blue_marble_y][marble.blue_marble_x + 1] == '#'){break;}
				else if (marble.blue_marble_y == marble.red_marble_y && marble.blue_marble_x + 1 == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y][marble.blue_marble_x + 1] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_x++;
			}
			while (1){
				if (marble_map[marble.red_marble_y][marble.red_marble_x + 1] == '#'){break;}
				else if (marble.red_marble_y == marble.blue_marble_y && marble.red_marble_x + 1 == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y][marble.red_marble_x + 1] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_x++;
			}
		}
	}
	else if (direction == 'U'){
		if (marble.red_marble_y < marble.blue_marble_y){
			while (1){
				if (marble_map[marble.red_marble_y - 1][marble.red_marble_x] == '#'){break;}
				else if (marble.red_marble_y - 1 == marble.blue_marble_y && marble.red_marble_x == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y - 1][marble.red_marble_x] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_y--;
			}
			while (1){
				if (marble_map[marble.blue_marble_y - 1][marble.blue_marble_x] == '#'){break;}
				else if (marble.blue_marble_y - 1 == marble.red_marble_y && marble.blue_marble_x == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y - 1][marble.blue_marble_x] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_y--;
			}
		}
		else {
			while (1){
				if (marble_map[marble.blue_marble_y - 1][marble.blue_marble_x] == '#'){break;}
				else if (marble.blue_marble_y - 1 == marble.red_marble_y && marble.blue_marble_x == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y - 1][marble.blue_marble_x] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_y--;
			}
			while (1){
				if (marble_map[marble.red_marble_y - 1][marble.red_marble_x] == '#'){break;}
				else if (marble.red_marble_y - 1 == marble.blue_marble_y && marble.red_marble_x == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y - 1][marble.red_marble_x] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_y--;
			}
		}
	}
	else if (direction == 'D'){
		if (marble.red_marble_y > marble.blue_marble_y){
			while (1){
				if (marble_map[marble.red_marble_y + 1][marble.red_marble_x] == '#'){break;}
				else if (marble.red_marble_y + 1 == marble.blue_marble_y && marble.red_marble_x == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y + 1][marble.red_marble_x] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_y++;
			}
			while (1){
				if (marble_map[marble.blue_marble_y + 1][marble.blue_marble_x] == '#'){break;}
				else if (marble.blue_marble_y + 1 == marble.red_marble_y && marble.blue_marble_x == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y + 1][marble.blue_marble_x] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_y++;
			}
		}
		else {
			while (1){
				if (marble_map[marble.blue_marble_y + 1][marble.blue_marble_x] == '#'){break;}
				else if (marble.blue_marble_y + 1 == marble.red_marble_y && marble.blue_marble_x == marble.red_marble_x){break;}
				else if (marble_map[marble.blue_marble_y + 1][marble.blue_marble_x] == 'O'){ // 파란 구슬이 구멍에 들어가면 안 됨
					blue_exit = true;
					marble.blue_marble_y = 0; marble.blue_marble_x = 0;
					break;
				}
				marble.blue_marble_y++;
			}
			while (1){
				if (marble_map[marble.red_marble_y + 1][marble.red_marble_x] == '#'){break;}
				else if (marble.red_marble_y + 1 == marble.blue_marble_y && marble.red_marble_x == marble.blue_marble_x){break;}
				else if (marble_map[marble.red_marble_y + 1][marble.red_marble_x] == 'O'){// 빨간 구슬이 들어가야 함
					red_exit = true;
					marble.red_marble_y = 0; marble.red_marble_x = 0;
					break;
				}
				marble.red_marble_y++;
			}
		}
	}
	if (blue_exit == true){return;}
	else if (blue_exit == false && red_exit == true){
		can_exit = true;
		return;
	}
	if (visit[marble.red_marble_y][marble.red_marble_x][marble.blue_marble_y][marble.blue_marble_x] == true){return;} // 이미 이 배치가 있었던 적이 있다면
	visit[marble.red_marble_y][marble.red_marble_x][marble.blue_marble_y][marble.blue_marble_x] = true;
	if (temp != marble){q.push(marble);}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	Marble marble = Marble(0, 0, 0, 0);
	cin >> N >> M;
	for (int n = 1; n <= N; n++){
		cin >> s;
		for (int m = 1; m <= M; m++){
			marble_map[n][m] = s[m - 1];
			if (marble_map[n][m] == 'R'){
				marble.red_marble_y = n;
				marble.red_marble_x = m;
			}
			else if (marble_map[n][m] == 'B'){
				marble.blue_marble_y = n;
				marble.blue_marble_x = m;
			}
		}
	}
	q.push(marble);
	visit[marble.red_marble_y][marble.red_marble_x][marble.blue_marble_y][marble.blue_marble_x] = true;
	while (!q.empty() && can_exit == false){
		move_count++;
		qsize = q.size();
		while (qsize-- > 0 && can_exit == false){
			marble = q.front();
			q.pop();
			MOVE(marble, 'L');
			MOVE(marble, 'R');
			MOVE(marble, 'U');
			MOVE(marble, 'D');
		}
	}
	if (can_exit == false){cout << -1;}
	else {cout << move_count;}
}