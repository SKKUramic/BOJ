// 1799 비숍
// https://www.acmicpc.net/problem/1799
// 9663 N-Queen 문제와 매우 비슷하다 https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

int N, limit, max_count[2];
int board[10][10];
int cannot_place[10][10] = {0, };
int color_list[10][10] = {0, };

void init(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cannot_place[i][j] = 0;
		}
	}
	return;
}

void fill_cannot(int y, int x){ // 비숍을 둔 후 못 가게 된 곳을 갱신함
	int temp_y, temp_x, temp;
	temp = cannot_place[y][x];
	temp_y = y; temp_x = x;
	while (temp_y < N && temp_x < N){
		cannot_place[temp_y][temp_x]++;
		temp_y++;
		temp_x++;
	}
	temp_y = y; temp_x = x;
	while (temp_y < N && temp_x >= 0){
		cannot_place[temp_y][temp_x]++;
		temp_y++;
		temp_x--;
	}
	temp_y = y; temp_x = x;
	while (temp_y >= 0 && temp_x < N){
		cannot_place[temp_y][temp_x]++;
		temp_y--;
		temp_x++;
	}
	temp_y = y; temp_x = x;
	while (temp_y >= 0 && temp_x >= 0){
		cannot_place[temp_y][temp_x]++;
		temp_y--;
		temp_x--;
	}
	cannot_place[y][x] = temp + 1;
	return;
}

void remove_cannot(int y, int x){ // 비숍을 제거한 후 갈 수 있게 된 곳을 갱신
	int temp_y, temp_x, temp;
	temp = cannot_place[y][x];
	temp_y = y; temp_x = x;
	while (temp_y < N && temp_x < N){
		cannot_place[temp_y][temp_x]--;
		temp_y++;
		temp_x++;
	}
	temp_y = y; temp_x = x;
	while (temp_y < N && temp_x >= 0){
		cannot_place[temp_y][temp_x]--;
		temp_y++;
		temp_x--;
	}
	temp_y = y; temp_x = x;
	while (temp_y >= 0 && temp_x < N){
		cannot_place[temp_y][temp_x]--;
		temp_y--;
		temp_x++;
	}
	temp_y = y; temp_x = x;
	while (temp_y >= 0 && temp_x >= 0){
		cannot_place[temp_y][temp_x]--;
		temp_y--;
		temp_x--;
	}
	cannot_place[y][x] = temp - 1;
	return;
}

void bishop(int y, int x, int count, int color){
	if (count > max_count[color]){max_count[color] = count;}
	int idx_y, idx_x;
	for (int idx = y * N + x + 1; idx < limit; idx++){
		idx_y = idx / N; idx_x = idx % N;
		if (color_list[idx_y][idx_x] != color){continue;} // 같은 색깔에 대해서만 검사함, 비숍은 다른 색깔로 이동할 수 없기 때문
		if (board[idx_y][idx_x] == 1 && cannot_place[idx_y][idx_x] == 0){
			fill_cannot(idx_y, idx_x);
			bishop(idx_y, idx_x, count + 1, color);
			remove_cannot(idx_y, idx_x);
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count, y, x, current_color; // Black = 0, White = 1
	cin >> N;
	limit = N * N;
	for (int i = 0; i < N; i++){
		current_color = i % 2;
		for (int j = 0; j < N; j++){
			cin >> board[i][j];
			color_list[i][j] = current_color;
			current_color = (current_color + 1) % 2;
		}
	}
	for (int idx = 0; idx < limit; idx++){
		init();
		y = idx / N; x = idx % N;
		if (board[y][x] == 1 && cannot_place[y][x] == 0){
			fill_cannot(y, x);
			bishop(y, x, 1, color_list[y][x]);
			remove_cannot(y, x);
		}
	}
	cout << max_count[0] + max_count[1];
}