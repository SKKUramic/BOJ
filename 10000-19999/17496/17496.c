// 17496 스타후르츠
#include <stdio.h>

int main(){
	int days, star_days, star_count, star_price;
	scanf("%d %d %d %d", &days, &star_days, &star_count, &star_price);
	printf("%d", ((days - 1) / star_days) * star_count * star_price);
}