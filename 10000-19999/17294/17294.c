// 17294 귀여운 수~ε٩(๑> ₃ <)۶з
// https://www.acmicpc.net/problem/17294
#include <stdio.h>

int main(){
	long long L, a, r;
	scanf("%lld", &L);
	if (L < 100){
		printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
		return 0;
	}
	a = L % 10; L /= 10;
	r = L % 10 - a; L /= 10;
	a += r;
	while (L > 0){
		if (L % 10 - a != r){
			printf("흥칫뿡!! <(￣ ﹌ ￣)>");
			return 0;
		}
		L /= 10;
		a += r;
	}
	printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
}