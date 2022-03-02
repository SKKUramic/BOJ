// 20499 Darius님 한타 안 함?
// https://www.acmicpc.net/problem/20499
#include <stdio.h>

int main(){
	int K, D, A; 
	scanf("%d/%d/%d", &K, &D, &A);
	if (D == 0 || K + A < D){
		printf("hasu");
	}
	else {
		printf("gosu");
	}
}