// 10569 다면체
// https://www.acmicpc.net/problem/10569
#include <stdio.h>

int main(){
	int T, V, E;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d %d", &V, &E);
		printf("%d\n", 2 - (V - E));
	}
}