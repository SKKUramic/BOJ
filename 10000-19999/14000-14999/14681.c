// 14681 사분면 고르기
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a > 0){
		if (b > 0){
			printf("1");
		}
		else {
			printf("4");
		}
	}
	else {
		if (b > 0){
			printf("2");
		}
		else {
			printf("3");
		}
	}
}