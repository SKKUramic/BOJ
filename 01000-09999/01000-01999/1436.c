// 1436 영화감독 숌
#include <stdio.h>

int main(){
	int N, count = 0, six_count, temp, num = 665;
	scanf("%d", &N);
	while (N != count){
		num++;
		temp = num;
		while (temp > 0 && six_count != 3){
			if (temp % 10 == 6) {six_count++;}
			else {six_count = 0;}
			temp /= 10;
		}
		if (six_count == 3){count++;}
		six_count = 0;
	}
	printf("%d", num);
}