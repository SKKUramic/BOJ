// 3052 나머지
#include <stdio.h>

int main(int argc, char* argv[]) {
	int arr[42] = {0, };
	int x, count = 0;
	for (int i = 0; i < 10; i++){
		scanf("%d", &x);
		if (arr[x % 42]++ == 0){
			count++;
		}
	}
	printf("%d", count);
}