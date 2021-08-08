// 10993 별 찍기 - 18
// https://www.acmicpc.net/problem/10993
#include <stdio.h>

int N;
char STAR[1500][3000]; // 세로줄은 2^N - 1, 가로줄은 2^(N + 1) - 3

void init(){
	for (int i = 0; i < 1500; i++){
		for (int j = 0; j < 3000; j++){
			STAR[i][j] = ' ';
		}
	}
	return;
}

int POW_2(int x){
	int pow = 1;
	for (int i = 0; i < x; i++){
		pow *= 2;
	}
	return pow;
}

void print_star(int n, int x, int y){
	if (n == 1){
		STAR[y][x] = '*';
		return;
	}
	int dest; // 밑변, 혹은 윗변(일자로 별을 출력할 y좌표)를 지정
	if (n % 2 == 0){ // 지금 별을 입력할 삼각형이 뒤집힌 것일 때
		dest = y - (POW_2(n) - 2);
		for (int i = y; i >= dest; i--){
			if (i == dest){ //별을 일자로 입력, 즉 삼각형의 윗변을 그림
				for (int j = x - (y - i); j <= x + (y - i); j++){
					STAR[i][j] = '*';
				}
			}
			else {//삼각형의 양옆 두 변을 그림, i == y이면 아래꼭지점이므로 하나만 찍음
				STAR[i][x + (y - i)] = '*';
				STAR[i][x - (y - i)] = '*';
			}
		} 
	}
	else if (n % 2 == 1){ // 지금 별을 입력할 삼각형이 정상일 때
		dest = y + POW_2(n) - 2;
		for (int i = y; i <= dest; i++){
			if (i == dest){ // 별을 일자로 입력, 즉 삼각형의 밑변을 그림
				for (int j = x - (i - y); j <= x + (i - y); j++){
					STAR[i][j] = '*';
				}
			}
			else {//삼각형의 양옆 두 변을 그림, i == y이면 위꼭지점이므로 하나만 찍음
				STAR[i][x + (i - y)] = '*';
				STAR[i][x - (i - y)] = '*';
			}
		} 
	}
	
	if (N % 2 == 0){ // 출력해야 할 삼각형이 뒤집힌 것일 때
		if ((N - n) % 2 == 0){
			print_star(n - 1, x, dest + 1); //일자로 출력한 곳 바로 아랫줄을 y로 지정
		}
		else {
			print_star(n - 1, x, dest - 1); //일자로 출력한 곳 바로 윗줄을 y로 지정
		}
	}
	else if (N % 2 == 1){ // 출력해야 할 삼각형이 정상일 때
		if ((N - n) % 2 == 0){
			print_star(n - 1, x, dest - 1); //일자로 출력한 곳 바로 윗줄을 y로 지정
		}
		else {
			print_star(n - 1, x, dest + 1); //일자로 출력한 곳 바로 아랫줄을 y로 지정
		}
	}
	return;
}

int main(){
	int pow = 1;
	int x, y, print_idx;
	scanf("%d", &N);
	if (N == 1){
		printf("*\n");
		return 0;
	}
	init(); // 배열 초기화
	x = POW_2(N) - 1;
	y = POW_2(N) - 1;
	print_idx = POW_2(N) - 1;
	if (N % 2 == 0){ // 출력해야 할 삼각형이 뒤집힌 것일 때
		print_star(N, x - 1, y - 1);
		for (int i = 0; i < print_idx; i++){
			for (int j = 0; j < 2 * print_idx - 1 - i; j++){
				printf("%c", STAR[i][j]);
			}
			printf("\n");
		}
	}
	else if (N % 2 == 1){ // 출력해야 할 삼각형이 정상일 때
		print_star(N, x - 1, 0);
		for (int i = 0; i < print_idx; i++){
			for (int j = 0; j < print_idx + i; j++){
				printf("%c", STAR[i][j]);
			}
			printf("\n");
		}
	}
}