// 7677 Fibonacci
// https://www.acmicpc.net/problem/7677
#include <stdio.h>

int fibonacci[2][2] = {{1, 1}, {1, 0}};
int answer[2][2] = {{1, 0}, {0, 1}}; // 단위행렬
int temp[2][2];

void init(){
	fibonacci[0][0] = 1;
	fibonacci[0][1] = 1;
	fibonacci[1][0] = 1;
	fibonacci[1][1] = 0;
	answer[0][0] = 1;
	answer[0][1] = 0;
	answer[1][0] = 0;
	answer[1][1] = 1;
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	while (n != -1){
		init();
		while (n > 0){ // 충격! 행렬곱을 손수 하는 미친 놈이 있다??
			if (n % 2 == 1){
				temp[0][0] = (answer[0][0] * fibonacci[0][0] + answer[0][1] * fibonacci[1][0]) % 10000;
				temp[0][1] = (answer[0][0] * fibonacci[0][1] + answer[0][1] * fibonacci[1][1]) % 10000;
				temp[1][0] = (answer[1][0] * fibonacci[0][0] + answer[1][1] * fibonacci[1][0]) % 10000;
				temp[1][1] = (answer[1][0] * fibonacci[0][1] + answer[1][1] * fibonacci[1][1]) % 10000;
				for (int i = 0; i < 2; i++){for(int j = 0; j < 2; j++){answer[i][j] = temp[i][j];}}
			}
			temp[0][0] = (fibonacci[0][0] * fibonacci[0][0] + fibonacci[0][1] * fibonacci[1][0]) % 10000;
			temp[0][1] = (fibonacci[0][0] * fibonacci[0][1] + fibonacci[0][1] * fibonacci[1][1]) % 10000;
			temp[1][0] = (fibonacci[1][0] * fibonacci[0][0] + fibonacci[1][1] * fibonacci[1][0]) % 10000;
			temp[1][1] = (fibonacci[1][0] * fibonacci[0][1] + fibonacci[1][1] * fibonacci[1][1]) % 10000;
			for (int i = 0; i < 2; i++){for(int j = 0; j < 2; j++){fibonacci[i][j] = temp[i][j];}}
			n /= 2;
		}
		printf("%d\n", answer[0][1]);
		scanf("%d", &n);
	}
}