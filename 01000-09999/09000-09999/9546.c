// 9546 3000번 버스
// https://www.acmicpc.net/problem/9546
#include <stdio.h>

int main(){
	int TC, n, answer;
	scanf("%d", &TC);
	while (TC-- > 0){
		answer = 1;
		scanf("%d", &n);
		for (int i = 1; i < n; i++){
			answer = answer * 2 + 1; // 역산
		}
		printf("%d\n", answer);
	}
}