// 1964 오각형, 오각형, 오각형…
// https://www.acmicpc.net/problem/1964
#include <stdio.h>

int main(){
	int N, point_count = 1, plus = 4;
	scanf("%d", &N);
	while (N-- > 0){
		point_count = (point_count + plus) % 45678;
		plus = (plus + 3) % 45678;
	}
	printf("%d", point_count);
}