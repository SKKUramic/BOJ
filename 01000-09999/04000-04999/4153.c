// 4153 직각삼각형
#include <stdio.h>

int main(){
	int x, y, z;
	int x2, y2, z2;
	while (1){
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0){break;}
		x2 = x * x; y2 = y * y; z2 = z * z;
		if (x2 + y2 == z2 || y2 + z2 == x2 || z2 + x2 == y2){
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
}