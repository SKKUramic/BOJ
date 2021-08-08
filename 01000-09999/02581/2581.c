// 2581 소수
#include <stdio.h>

int main(){
	int start, end, flags = 0, answer = 0, min = 0;
	scanf("%d", &start);
	scanf("%d", &end);
	for (int i = start; i <= end; i++){
		for (int k = 2; k <= i; k++){
			if (i % k == 0){
				flags++;
			}
		}
		if (flags == 1){
			answer += i;
			if (min == 0){
				min = i;
			}
		}
		flags = 0;
	}
	if (answer == 0 && min == 0){
		printf("-1");
	}
	else {
		printf("%d\n%d", answer, min);
	}
}