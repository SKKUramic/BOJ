// 18004 From A to B
// https://www.acmicpc.net/problem/18004
#include <stdio.h>

int main(){
	int a, b, count = 0;
	scanf("%d %d", &a, &b);
	while (a != b){
		if (a < b){
			a++;
		}
		else {
			if (a % 2 == 0){
				a /= 2;
			}
			else {
				a++;
			}
		}
		count++;
	}
	printf("%d", count);
}