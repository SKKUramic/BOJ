// 1330 두 수 비교하기
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b){
		printf(">");
	}
	else if (a < b){
		printf("<");
	}
	else {
		printf("==");
	}
}