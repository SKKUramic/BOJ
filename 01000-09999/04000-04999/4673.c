// 4673 셀프넘버
#include <stdio.h>
#include <stdlib.h>

int self_number[10000] = {0, };
int removed = 0;

void d(int x){
	int temp = x;
	if (x > 10000){
		return;
	}
	else {
		if (self_number[x] == 0){
			if (removed != 0){
				self_number[x] = 1;
			}
			removed++;
		}
		while (temp > 0){
			x += temp % 10;
			temp /= 10;
		}
		d(x);
	}
}

int main(){
	int self = 1;
	do {
		removed = 0;
		d(self);
		while(self_number[++self] != 0){
		}
	} while (removed > 0 && self <= 10000);
	self = 1;
	while(self < 10000){
		if (self_number[self] == 0){
			printf("%d\n", self);
		}
		self++;
	}
}