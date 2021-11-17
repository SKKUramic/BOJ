// 14491 9진수
// https://www.acmicpc.net/problem/14491
#include <stdio.h>

int main(){
	int T, nine[10], idx = 0;
	scanf("%d", &T);
	while (T > 0){
		nine[idx++] = T % 9;
		T /= 9;
	}
	for (int i = idx - 1; i >= 0; i--){
		printf("%d", nine[i]);
	}
}