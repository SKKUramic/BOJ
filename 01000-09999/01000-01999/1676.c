// 1676 팩토리얼 0의 개수
#include <stdio.h>

int main(){
	int facto, temp, two_count = 0, five_count = 0;
	scanf("%d", &facto);
	for (int i = 1; i <= facto; i++){
		if (i % 2 == 0 || i % 5 == 0){
			temp = i;
			while (temp % 2 == 0){
				temp /= 2;
				two_count++;
			}
			while (temp % 5 == 0){
				temp /= 5;
				five_count++;
			}
		}
	}
	printf("%d", two_count < five_count ? two_count : five_count);
}