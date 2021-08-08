// 9663 N-Queen
#include <iostream>
#include <cstdlib>
using namespace std;

int board[15];
int N, answer = 0;
bool can_place;

void Nqueen(int queen){
	//bool can_place;
	if (queen == N){
		answer++;
		return;
	}
	for (int i = 0; i < N; i++){
		can_place = true;
		for (int j = 0; j < queen; j++){
			if (board[j] == i || abs(i - board[j]) == abs(queen - j)){
				can_place = false;
				break;
			}
		}
		if (can_place){
			board[queen] = i;
			Nqueen(queen + 1);
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	Nqueen(0);
	cout << answer;
}



/* timeout code
#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 0, queen_count = 0;
int queen_pos[20][2]; //[0] = x, [1] = y

bool queen_tf(int x1, int y1){
	int x2, y2;
	for (int i = 0; i < queen_count; i++){
		x2 = queen_pos[i][0];
		y2 = queen_pos[i][1];
		if (x2 == -1 || y2 == -1){return true;}
		if ((x1 == x2) || (y2 == y1) || ((x2 - x1) * (x2 - x1) == (y2 - y1) * (y2 - y1)))
			return false;
		// x가 같거나, y가 같거나, 대각에 위치해 있을 경우 false 리턴
	}
	return true;
}

void init(){
	for (int i = 0; i < N; i++){
		queen_pos[i][0] = -1;
		queen_pos[i][1] = -1;
	}
	return;
}

void queen(int cnt){
	int x = cnt / N;
	int y = cnt % N;
	if (!queen_tf(x, y)){
		return;
	}
	if (queen_count == N - 1){
		answer++;
		return;
	}
	for (int j = 0; j < N; j++){
		queen_pos[queen_count][0] = x;
		queen_pos[queen_count][1] = y;
		queen_count++;
		queen(queen_count * N + j);
		queen_count--;
		queen_pos[queen_count][0] = -1;
		queen_pos[queen_count][1] = -1;
	}
	return;
}

int main(void){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	init();
	for (int a = 0; a < N; a++){
		queen(a);
	}
	cout << answer;
	return 0;
}

*/