// 12100 2048 (Easy)
// https://www.acmicpc.net/problem/12100
#include <iostream>
using namespace std;

const int LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4;
int N;
int Square[3126][21][21] = {0, };

void play_game(int try_count, int arr_idx){
    if (try_count > 5){return;}
    int idx;
	if (arr_idx % 5 == LEFT){
		for (int a = 0; a < N; a++){
			idx = 0;
            for (int b = 0; b < N; b++){
                if (Square[arr_idx / 5][a][b] == 0){continue;}
                if (b == N - 1){
                    if (Square[arr_idx / 5][a][b] != 0){
                        Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
                    }
                }
                for (int c = 1; c < N - b; c++){
                    if (Square[arr_idx / 5][a][b] == Square[arr_idx / 5][a][b + c]){
                        Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b] + Square[arr_idx / 5][a][b + c];
                        b += c;
                        idx++;
                        break;
                    }
                    else if (Square[arr_idx / 5][a][b] != Square[arr_idx / 5][a][b + c]){
                        if (Square[arr_idx / 5][a][b + c] != 0){
                            Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
                            b += (c - 1);
                            idx++;
                            break;
                        }
                    }
                    if (b + c == N - 1){ // 끝까지 0이었을 때
						Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
						b = N - 1;
						idx++;
                    }
                }
            }
        }
    }
    else if (arr_idx % 5 == RIGHT){
        for (int a = 0; a < N; a++){
            idx = N - 1;
            for (int b = N - 1; b >= 0; b--){
                if (Square[arr_idx / 5][a][b] == 0){continue;}
                if (b == 0){
                    if (Square[arr_idx / 5][a][b] != 0){
                        Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
                    }
                }
                for (int c = 1; c <= b; c++){
                    if (Square[arr_idx / 5][a][b] == Square[arr_idx / 5][a][b - c]){
                        Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b] + Square[arr_idx / 5][a][b - c];
                        b -= c;
                        idx--;
                        break;
                    }
                    else if (Square[arr_idx / 5][a][b] != Square[arr_idx / 5][a][b - c]){
                        if (Square[arr_idx / 5][a][b - c] != 0){
                            Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
                            b -= (c - 1);
                            idx--;
                            break;
                        }
                    }
                    if (b - c == 0){
						Square[arr_idx][a][idx] = Square[arr_idx / 5][a][b];
                        b = 0;
						idx++;
                    }
                }
            }
        }
    }
    else if (arr_idx % 5 == UP){
        for (int a = 0; a < N; a++){
            idx = 0;
            for (int b = 0; b < N; b++){
                if (Square[arr_idx / 5][b][a] == 0){continue;}
				if (b == N - 1){
					if (Square[arr_idx / 5][b][a] != 0){
                        Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                    }
				}
                for (int c = 1; c < N - b; c++){
                    if (Square[arr_idx / 5][b][a] == Square[arr_idx / 5][b + c][a]){
                        Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a] + Square[arr_idx / 5][b + c][a];
                        b += c;
                        idx++;
                        break;
                    }
                    else if (Square[arr_idx / 5][b][a] != Square[arr_idx / 5][b + c][a]){
                        if (Square[arr_idx / 5][b + c][a] != 0){
                            Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                            b += (c - 1);
                            idx++;
                            break;
                        }
                    }
                    if (b + c == N - 1){
						Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                        b = N - 1;
						idx++;
                    }
                }
            }
        }
    }
    else if (arr_idx % 5 == DOWN){
        for (int a = 0; a < N; a++){
            idx = N - 1;
            for (int b = N - 1; b >= 0; b--){
                if (Square[arr_idx / 5][b][a] == 0){continue;}
                if (b == 0){
                    if (Square[arr_idx / 5][b][a] != 0){
                        Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                    }
                }
                for (int c = 1; c <= b; c++){
                    if (Square[arr_idx / 5][b][a] == Square[arr_idx / 5][b - c][a]){
                        Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a] + Square[arr_idx / 5][b - c][a];
                        b -= c;
                        idx--;
                        break;
                    }
                    else if (Square[arr_idx / 5][b][a] != Square[arr_idx / 5][b - c][a]){
                        if (Square[arr_idx / 5][b - c][a] != 0){
                            Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                            b -= (c - 1);
                            idx--;
                            break;
                        }
                    }
                    if (b - c == 0){
						Square[arr_idx][idx][a] = Square[arr_idx / 5][b][a];
                        b = 0;
						idx++;
                    }
                }
            }
        }
    }
    play_game(try_count + 1, arr_idx * 5 + LEFT);
    play_game(try_count + 1, arr_idx * 5 + RIGHT);
    play_game(try_count + 1, arr_idx * 5 + UP);
    play_game(try_count + 1, arr_idx * 5 + DOWN);
    return;
}

int main(){
    int max = -1;
    cin >> N;
    for (int a = 0; a < N; a++){
        for (int b = 0; b < N; b++){
            cin >> Square[0][a][b];
        }
    }
    play_game(1, LEFT);
    play_game(1, RIGHT);
    play_game(1, UP);
    play_game(1, DOWN);
    for (int a = 0; a < 3125; a++){
        for (int b = 0; b < N; b++){
            for (int c = 0; c < N; c++){
                if (Square[a][b][c] > max){
                    max = Square[a][b][c];
                }
            }
        }
    }
    cout << max;
}