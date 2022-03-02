// 16926 배열 돌리기 1
// https://www.acmicpc.net/problem/16926
#include <stdio.h>
#define debug 0

int arr[301][301];
int N, M, R;

void print_arr(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}

void Counter_Clock_Spin(){
	int x, y;
	int min_side = N < M ? N : M;
	min_side /= 2;
	for (int idx = 0; idx < min_side; idx++){ // 빙글빙글 반시계 방향으로 돌림
		int temp = arr[idx][idx];
		x = idx; y = idx;
		while (x < M - idx - 1){
			arr[y][x] = arr[y][x + 1];
			x++;
		}
		while (y < N - idx - 1){
			arr[y][x] = arr[y + 1][x];
			y++;
		}
		while (x > idx){
			arr[y][x] = arr[y][x - 1];
			x--;
		}
		while (y > idx){
			arr[y][x] = arr[y - 1][x];
			y--;
		}
		arr[idx + 1][idx] = temp;
		#if debug
		printf("Spinning %d...\n", idx);
		print_arr();
		printf("\n");
		#endif
	}
	return;
}

int main(){
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < R; i++){
		Counter_Clock_Spin();
	}
	print_arr();
}