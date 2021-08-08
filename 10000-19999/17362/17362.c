// 17362 수학은 체육과목 입니다 2
// https://www.acmicpc.net/problem/17362
#include <stdio.h>

int finger[8] = {1, 2, 3, 4, 5, 4, 3, 2};

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", finger[(N - 1) % 8]);
}