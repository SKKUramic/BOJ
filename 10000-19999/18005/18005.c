// 18005 Even or Odd?
// https://www.acmicpc.net/problem/18005
// 21185 문제와 같다. 그냥 n의 범위만 다를 뿐
#include <stdio.h>

int main(){
	int sum, n;
	scanf("%d", &n);
	if (n % 2 == 1){
		printf("0");
	}
	else {
		if ((n / 2) % 2 == 1){
			printf("1");
		}
		else {
			printf("2");
		}
	}
}