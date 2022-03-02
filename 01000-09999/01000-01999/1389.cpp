// 1389 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389
#include <iostream>
using namespace std;

int Graph[101][101] = {0, };

void Floyd_Warshall(int n){
	for (int k = 1; k <= n; k++){
		for (int start = 1; start <= n; start++){
			for (int end = 1; end <= n; end++){
				if (start == end){ // 자기 자신으로의 경로는 무시한다.
					continue;
				}
				else if (Graph[start][k] != 0 && Graph[k][end] != 0){
					if (Graph[start][end] == 0){ // 아직 경로가 발견되지 않은 경우, 경로를 넣어준다.
						Graph[start][end] = Graph[start][k] + Graph[k][end];
					}
					else { // 경로 최소화
						Graph[start][end] = min(Graph[start][end], Graph[start][k] + Graph[k][end]);
					}
				}
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Kevin_Bacon_min_value = 99999, Kevin_Bacon_min_User = 99999;
	int User, Friend, x, y, road_to_another_user;
	cin >> User >> Friend;
	for (int i = 0; i < Friend; i++){
		cin >> x >> y;
		Graph[x][y] = Graph[y][x] = 1;
	}
	Floyd_Warshall(User);
	for (int i = 1; i <= User; i++){
		road_to_another_user = 0;
		for (int j = 1; j <= User; j++){
			if (i == j){continue;}
			road_to_another_user += Graph[i][j];
		}
		if (road_to_another_user < Kevin_Bacon_min_value){
			Kevin_Bacon_min_User = i;
			Kevin_Bacon_min_value = road_to_another_user;
		}
	}
	cout << Kevin_Bacon_min_User;
}