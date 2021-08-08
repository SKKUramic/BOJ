// 14500 테트로미노
// https://www.acmicpc.net/problem/14500
#include <stdio.h>

int N, M, biggest_value = -1;
int arr[501][501];

int MAX(int a, int b){return a > b ? a : b;}

void TETROMINO(int y, int x){
	// I, O, T, (J, L), (S, Z) 순으로 검사
	int value_sum;
	// I 조사
	if (x + 3 < M){
		value_sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
		biggest_value = MAX(biggest_value, value_sum);
	}
	if (y + 3 < N){
		value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
		biggest_value = MAX(biggest_value, value_sum);
	}
	// O 조사
	if (y < N - 1 && x < M - 1){
		value_sum = arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x + 1];
		biggest_value = MAX(biggest_value, value_sum);
	}
	// T 조사
	if (x + 2 < M){ // T 가로로 긴 것 검사
		if (y < N - 1){ // 아래쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (y > 0){ // 위쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (y + 2 < N){ // T 세로로 긴 것 검사
		if (x < M - 1){ // 오른쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (x > 0){ // 왼쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	// (J, L) 조사
	if (x + 2 < M){ // J,L 오른쪽으로 긴 것 검사
		if (y < N - 1){ // 아래쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (y > 0){ // 위쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (y + 2 < N){ // J,L 아래로 긴 것 검사
		if (x < M - 1){ // 오른쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (x > 0){ // 왼쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x - 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (x > 1){ // J,L 왼쪽으로 긴 것 검사
		if (y < N - 1){ // 아래쪽
			value_sum = arr[y][x] + arr[y][x - 1] + arr[y][x - 2] + arr[y + 1][x - 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (y > 0){ // 위쪽
			value_sum = arr[y][x] + arr[y][x - 1] + arr[y][x - 2] + arr[y - 1][x - 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (y > 1){ // J,L 위로 긴 것 검사
		if (x < M - 1){ // 오른쪽
			value_sum = arr[y][x] + arr[y - 1][x] + arr[y - 2][x] + arr[y - 2][x + 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (x > 0){ // 왼쪽
			value_sum = arr[y][x] + arr[y - 1][x] + arr[y - 2][x] + arr[y - 2][x - 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	// (S, Z) 조사
	if (x + 2 < M){ // S,Z 오른쪽으로 향한 것 검사
		if (y < N - 1){ // 아래쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (y > 0){ // 위쪽
			value_sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y - 1][x + 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (y + 2 < N){ // S,Z 아래로 향한 것 검사
		if (x < M - 1){ // 오른쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (x > 0){ // 왼쪽
			value_sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x - 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (x > 1){ // S,Z 왼쪽으로 향한 것 검사
		if (y < N - 1){ // 아래쪽
			value_sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x - 1] + arr[y + 1][x - 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (y > 0){ // 위쪽
			value_sum = arr[y][x] + arr[y][x - 1] + arr[y - 1][x - 1] + arr[y - 1][x - 2];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	if (y > 1){ // S,Z 위로 향한 것 검사
		if (x < M - 1){ // 오른쪽
			value_sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x + 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
		if (x > 0){ // 왼쪽
			value_sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x - 1];
			biggest_value = MAX(biggest_value, value_sum);
		}
	}
	return;
}

int main(){
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++){
		for (int x = 0; x < M; x++){
			scanf("%d", &arr[y][x]);
		}
	}
	for (int y = 0; y < N; y++){
		for (int x = 0; x < M; x++){
			TETROMINO(y, x);
		}
	}
	printf("%d", biggest_value);
}