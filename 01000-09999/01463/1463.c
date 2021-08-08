// 1463 1로 만들기
#include <stdio.h>

int make_one[1000001] = {0, };

int main(){
	int number, temp;
	scanf("%d", &number);
	for (int i = 2; i <= number; i++){
		temp = 1000;
		if (i % 3 == 0){
			if (temp > make_one[i / 3]){
				temp = make_one[i / 3] + 1;
			}
		}
		if (i % 2 == 0){
			if (temp > make_one[i / 2]){
				temp = make_one[i / 2] + 1;
			}
		}
		if (temp > make_one[i - 1]){
			temp = make_one[i - 1] + 1;
		}
		make_one[i] = temp;
	}
	printf("%d", make_one[number]);
}