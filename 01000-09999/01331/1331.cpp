// 1331 나이트 투어
// https://www.acmicpc.net/problem/1331
#include <iostream>
#include <cstdlib>
using namespace std;

bool visited[6][6], invalid = false;

int main(){
	string s;
	int prev_x, prev_y, cur_x, cur_y, start_y, start_x;
	for (int i = 0; i < 36; i++){
		cin >> s;
		if (i == 0){
			prev_x = s[0] - 'A';
			prev_y = s[1] - '1';
			visited[prev_y][prev_x] = true;
			start_y = prev_y;
			start_x = prev_x;
		}
		else {
			cur_x = s[0] - 'A';
			cur_y = s[1] - '1';
			if (abs(prev_y - cur_y) * abs(prev_x - cur_x) != 2 || visited[cur_y][cur_x] == true){
				invalid = true;
			}
			visited[cur_y][cur_x] = true;
			prev_y = cur_y;
			prev_x = cur_x;
		}
	}
	if (abs(prev_y - start_y) * abs(prev_x - start_x) != 2){invalid = true;}
	if (invalid){cout << "Invalid";}
	else {cout << "Valid";}
}