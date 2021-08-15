// 14601 샤워실 바닥 깔기 (Large)
// https://www.acmicpc.net/problem/14601
#include <iostream>
#include <utility>
using namespace std;

int FLOOR[129][129];
int tile = 1;
int K;
pair<int, int> waterway;

int two_power(int k){
	int ret = 1;
	for (int i = 0; i < k; i++){ret *= 2;}
	return ret;
}

bool waterway_inside(int y, int x, int s){ // 해당하는 영역에 0 이외의 수(하수구가 있거나 이미 L트로미노의 일부가 들어있음)가 있을 경우 참 반환
	for (int a = y; a < y + s; a++){
		for (int b = x; b < x + s; b++){
			if (FLOOR[a][b] != 0){return true;}
		}
	}
	return false;
}

void fill_FLOOR(int y, int x, int k){ // 중심부터 채워나가는 함수
	if (k < 2){return;}
	int s = k / 2;
	if (waterway_inside(y, x, s) == false && FLOOR[y + s - 1][x + s - 1] == 0){FLOOR[y + s - 1][x + s - 1] = tile;}
	if (waterway_inside(y, x + s, s) == false && FLOOR[y + s - 1][x + s] == 0){FLOOR[y + s - 1][x + s] = tile;}
	if (waterway_inside(y + s, x, s) == false && FLOOR[y + s][x + s - 1] == 0){FLOOR[y + s][x + s - 1] = tile;}
	if (waterway_inside(y + s, x + s, s) == false && FLOOR[y + s][x + s] == 0){FLOOR[y + s][x + s] = tile;}
	tile++;
	if (k == 2){return;}
	fill_FLOOR(y, x, s);
	fill_FLOOR(y, x + s, s);
	fill_FLOOR(y + s, x, s);
	fill_FLOOR(y + s, x + s, s);
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	cin >> waterway.first >> waterway.second;
	K = two_power(K);
	FLOOR[waterway.first][waterway.second] = -1;
	fill_FLOOR(1, 1, K);
	for (int x = K; x >= 1; x--){
		for (int y = 1; y <= K; y++){
			cout << FLOOR[y][x] << ' ';
		}
		cout << '\n';
	}
}