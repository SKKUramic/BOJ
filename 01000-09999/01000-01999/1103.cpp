// 1103 게임
// https://www.acmicpc.net/problem/1103
#include <iostream>
#include <cstring>
using namespace std;

int DP[51][51];
bool visited[51][51];
char map[51][51];
int N, M;
bool cycle = false;

int MAX(int a, int b){return a > b ? a : b;}

bool OutOfRange(int y, int x){
	return !((0 <= y && y < N) && (0 <= x && x < M));
}

int DFS(int y, int x){
	if (map[y][x] == 'H' || OutOfRange(y, x) || cycle){return 0;} // 구멍이거나, 범위 밖이거나, 이미 사이클이 발견된 경우
	if (visited[y][x] == true){ // 사이클이 존재할 경우
		cycle = true;
		return 0;
	}
	if (DP[y][x] != -1){return DP[y][x];} // 이미 검증이 끝난 곳은 값을 리턴
	//cout << y << ' ' << x << '\n';
	visited[y][x] = true;
	DP[y][x] = 0; // 방문할 수 있는 곳이므로 DP값 초기화
	int move = map[y][x] - '0';
	//cout << "move : " << move << '\n';
	DP[y][x] = MAX(DP[y][x], DFS(y + move, x) + 1);
	DP[y][x] = MAX(DP[y][x], DFS(y, x + move) + 1);
	DP[y][x] = MAX(DP[y][x], DFS(y - move, x) + 1);
	DP[y][x] = MAX(DP[y][x], DFS(y, x - move) + 1);
	// 현재까지의 DP값과 비교하며 갱신
	//cout << "DP[y][x] : " << DP[y][x] << '\n';
	visited[y][x] = false;
	return DP[y][x];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	memset(DP, -1, sizeof(DP));
	for (int n = 0; n < N; n++){cin >> map[n];}
	int answer = DFS(0, 0);
	//for (int i = 0; i < N; i++){for (int j = 0; j < M; j++){cout << DP[i][j] << "\t\t";}cout << '\n';}
	if (cycle){cout << -1;}
	else {cout << answer;}
}

/*
5 5
2H2H2
HHHHH
2H2H2
HHHHH
2H2H2
*/