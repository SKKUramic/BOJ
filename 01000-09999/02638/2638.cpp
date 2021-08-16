// 2638 치즈
// https://www.acmicpc.net/problem/2638
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int exposed_air = 2;
int cheese_count = 0;
int cheese[101][101] = {0, };

void DFS(int y, int x){ // 공기에 노출된 공간을 판별하는 함수, 매번 갱신한다
	cheese[y][x] = exposed_air;
	if (y > 0 && cheese[y - 1][x] != 1 && cheese[y - 1][x] != exposed_air){
		DFS(y - 1, x);
	}
	if (y < N && cheese[y + 1][x] != 1 && cheese[y + 1][x] != exposed_air){
		DFS(y + 1, x);
	}
	if (x > 0 && cheese[y][x - 1] != 1 && cheese[y][x - 1] != exposed_air){
		DFS(y, x - 1);
	}
	if (x < M && cheese[y][x + 1] != 1 && cheese[y][x + 1] != exposed_air){
		DFS(y, x + 1);
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int exposed_count, time = 0;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> cheese[n][m];
			if (cheese[n][m] == 1) {cheese_count++;} // 치즈의 개수를 센다
		}
	}
	while (cheese_count > 0){
		DFS(0, 0);
		for (int n = 0; n < N; n++){
			for (int m = 0; m < M; m++){
				exposed_count = 0;
				if (cheese[n][m] == 1){ // 치즈가 이번에 녹는지 확인
					if (cheese[n - 1][m] == exposed_air){exposed_count++;}
					if (cheese[n + 1][m] == exposed_air){exposed_count++;}
					if (cheese[n][m - 1] == exposed_air){exposed_count++;}
					if (cheese[n][m + 1] == exposed_air){exposed_count++;}
					if (exposed_count >= 2){
						cheese[n][m] = 0;
						cheese_count--;
					}
				}
			}
		}
		exposed_air++; // 혹시 모르니 노출된 공기를 판별하는 값을 바꾸어간다
		time++;
	}
	cout << time;
}