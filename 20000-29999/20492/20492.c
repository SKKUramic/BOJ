//20492 세금
#include <stdio.h>

int main(){
	double money;
	scanf("%lf", &money);
	printf("%0.lf %0.lf", money * 0.78, money - money * 0.2 * 0.22);
}