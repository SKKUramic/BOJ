// 5565 영수증
// https://www.acmicpc.net/problem/5565
#include <stdio.h>

int main(){
	int sum = 0, ten_sum, num;
	scanf("%d", &ten_sum);
	for (int i = 0; i < 9; i++){
		scanf("%d", &num);
		sum += num;
	}
	printf("%d", ten_sum - sum);
}