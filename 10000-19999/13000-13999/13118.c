// 13118 뉴턴과 사과
// https://www.acmicpc.net/problem/13118
// 사실 신경써야 할 변수는 x좌표 뿐입니다.
#include <stdio.h>

int p[4];
int x, y, r;

int main(){
	for (int i = 0; i < 4; i++){
		scanf("%d", &p[i]);
	}
	scanf("%d %d %d", &x, &y, &r);
	for (int i = 0; i < 4; i++){
		if (p[i] == x){
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("0");
	return 0;
}