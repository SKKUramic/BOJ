// 1789 수들의 합
// https://www.acmicpc.net/problem/1789
#include <stdio.h>

int main(){
	long long S, sum = 0, num = 1, cnt = 0;
	scanf("%lld", &S);
	while (1){
		sum += num;
		cnt++;
		if (sum > S){
			cnt--;
			break;
		}
		num++;
	}
	printf("%lld", cnt);
}