// 9498 시험성적
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a;
	scanf("%d", &a);
	if (a >= 90){
		printf("A");
	}
	else if (a >= 80){
		printf("B");
	}
	else if (a >= 70){
		printf("C");
	}
	else if (a >= 60){
		printf("D");
	}
	else {
		printf("F");
	}
}