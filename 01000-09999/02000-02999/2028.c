// 2028 자기복제수
// https://www.acmicpc.net/problem/2028
#include <stdio.h>

int main(){
	int T, N, ten;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		ten = 1;
		while (ten <= N){
			ten *= 10;
		}
		if (N * N % ten == N){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}