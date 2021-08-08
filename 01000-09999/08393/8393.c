// 8393 합
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		sum += i;
	}  // 아 뭣하러 이렇게 하지ㅋㅋ
	printf("%d", sum);
}