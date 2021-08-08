// 16233 수학 문제
// https://www.acmicpc.net/problem/16233
#include <stdio.h>

int ret;

int digit_sum(int x){
	ret = 0;
	while (x > 0){
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main(){
	int T, num, maximum, minimum, i, answer;
	scanf("%d", &T);
	while (T-- > 0){
		answer = -1;
		scanf("%d", &num);
		if (num % 9 != 0){printf("-1 "); continue;}
		minimum = (num / 10) * 10;
		maximum = num + 100;
		// 여러 테스트케이스를 돌려본 결과 모든 답은 10으로 나누어떨어진다.
		for (i = minimum; i < maximum; i += 10){
			if (digit_sum(i) + num == i){
				answer = i;
				break;
			}
		}
		printf("%d ", answer);
	}
}