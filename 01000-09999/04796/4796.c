// 4796 캠핑
// https://www.acmicpc.net/problem/4796
#include <stdio.h>

int main(){
	long long vacation, open, use, case_num = 1, rest;
	scanf("%lld %lld %lld", &use, &open, &vacation);
	while (use != 0 || open != 0 || vacation != 0){
		rest = 0;
		while (vacation > 0){
			if (vacation >= use){
				rest += use;
			}
			else {
				rest += vacation;
			}
			vacation -= open;
		}
		printf("Case %lld: %lld\n", case_num, rest);
		case_num++;
		scanf("%lld %lld %lld", &use, &open, &vacation);
	}
}