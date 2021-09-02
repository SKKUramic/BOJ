// 6763 Speed fines are not fine!
// https://www.acmicpc.net/problem/6763
#include <stdio.h>

int main(){
	int limit, speed;
	scanf("%d", &limit);
	scanf("%d", &speed);
	if (speed <= limit){
		printf("Congratulations, you are within the speed limit!");
	}
	else {
		if (speed - limit > 30){
			printf("You are speeding and your fine is $500.");
		}
		else if (speed - limit > 20){
			printf("You are speeding and your fine is $270.");
		}
		else {
			printf("You are speeding and your fine is $100.");
		}
	}
}