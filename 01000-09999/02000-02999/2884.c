// 2884 알람 시계
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b, timer;
	scanf("%d %d", &a, &b);
	timer = 60 * a + b - 45;
	if (timer < 0){
		timer += 1440;
	}
	printf("%d %d", timer / 60, timer % 60);
}