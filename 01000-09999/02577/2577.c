// 숫자의 개수
#include <stdio.h>

int main(int argc, char* argv[]) {
	int arr[10] = {0, };
	int a, b, c, num;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	num = a * b * c;
	// printf("%d\n", num);
	while(num > 0){
		arr[num % 10]++;
		// printf("index: %d\n", num % 10);
		num /= 10;
		// printf("%d\n", num);
	}
	for (int i = 0; i < 10; i++){
		printf("%d\n", arr[i]);
	}
}