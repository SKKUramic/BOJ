// 1065 한수
#include <stdio.h>

int hansu(int x){
	int dif = 1009, x1, x2, temp;
	if (x < 100){
		return 1;
	}
	temp = x;
	x1 = temp % 10;
	temp /= 10;
	x2 = temp % 10;
	dif = x1 - x2;
	while (temp > 9){
		x1 = x2;
		temp /= 10;
		x2 = temp % 10;
		if (dif != x1 - x2){
			return 0;
		}
	}
	return 1;
	
}

int main(){
	int x, answer = 0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++){
		answer += hansu(i);
	}
	printf("%d", answer);
}