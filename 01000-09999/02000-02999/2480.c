// 2480 주사위 세개
#include <stdio.h>

int main(){
	int one, two, chachacha, price;
	scanf("%d %d %d", &one, &two, &chachacha);
	if (one == two){ // one == two == chachacha
		if (two == chachacha){
			price = 10000 + one * 1000;
		}
		else { //one == two != chachacha
			price = 1000 + one * 100;
		}
	}
	else if (two == chachacha){ // one != two == chachacha
		price = 1000 + two * 100;
	}
	else if (chachacha == one){ // one != two != chachacha == one
		price = 1000 + chachacha * 100;
	}
	else {
		if (one > two){
			if (one > chachacha){
				price = one * 100;
			}
			else {
				price = chachacha * 100;
			}
		}
		else {
			if (two > chachacha){
				price = two * 100;
			}
			else {
				price = chachacha * 100;
			}
		}
	}
	printf("%d", price);
}