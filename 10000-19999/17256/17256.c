//17256 달달함이 넘쳐흘러
#include <stdio.h>

int main(){
	int ax, ay, az, cx, cy, cz;
	scanf("%d %d %d", &ax, &ay, &az);
	scanf("%d %d %d", &cx, &cy, &cz);
	printf("%d %d %d", cx - az, cy / ay, cz - ax);
}