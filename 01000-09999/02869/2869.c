// 2869 달팽이는 올라가고 싶다
#include <stdio.h>

int main(){
	int A, B, V, diff, day;
	scanf("%d %d %d", &A, &B, &V);
	diff = A - B;
	V -= A;
	day = (V / diff) + 1;
	if (V % diff != 0){
		day++;
	}
	printf("%d", day);
}