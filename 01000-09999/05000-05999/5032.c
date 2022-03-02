// 5032 탄산 음료
// https://www.acmicpc.net/problem/5032
#include <stdio.h>

int main(){
	int e, f, c, ans = 0, can = 0;
	scanf("%d %d %d", &e, &f, &c);
	can = e + f;
	while (can >= c){
		ans += can / c;
		can = can / c + can % c;
	}
	printf("%d", ans);
}