// 15964 이상한 기호
#include <stdio.h>

int main(){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (a + b) * (a - b));
}