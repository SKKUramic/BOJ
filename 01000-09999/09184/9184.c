// 9184 신나는 함수 실행
#include <stdio.h>

int value[30][30][30] = {0, };
/*
int W(int a, int b, int c){
	if (a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	if (a > 20 || b > 20 || c > 20){
		return W(20, 20, 20);
	}
	if (a < b && b < c){
		return W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	}
	else {
		return W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
	}
}
*/
int w(int a, int b, int c){
	if (a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	if (a > 20 || b > 20 || c > 20){
		return w(20, 20, 20);
	}
	if (value[a][b][c] != 0){
		return value[a][b][c];
	}
	if (a < b && b < c){
		return value[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return value[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != -1 || b != -1 || c != -1){
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
	}
}